#include <iostream>
#include <cstdlib>
#include <ctime>
#include <opencv2/opencv.hpp>

// NAMESPACES
using namespace cv;
using namespace std;

// DEFINES (WASN'T ABLE TO GET IT TO WORK WITH DEFINES, IT MADE ME CHANGE TO THIS INSTEAD)
constexpr auto WINDOW_WIDTH = 500;
constexpr auto WINDOW_HEIGHT = 500;

// DEFINE COLORS
Scalar black(0, 0, 0);
Scalar red(0, 0, 255);
Scalar green(0, 255, 0);
Scalar blue(255, 0, 0);
Scalar purple(255, 0, 255);

// DEFINE SHAPES
enum ShapeType {
	CIRCLE,
	ELLIPSE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

// POSITION RANDOMIZER
inline Point getRandomPositionPoint() {
	return Point(rand() % 400 + 50, rand() % 400 + 50);
}

// RADIUS RANDOMIZER
inline int getRandomRadius() {
	return rand() % 50 + 10;
}

// COLOR RANDOMIZER
Scalar getRandomColor() {
	const int randomizedColor = rand() % 5 + 1;
	switch (randomizedColor) {
		case 1:
			return black;
		case 2:
			return red;
		case 3:
			return green;
		case 4:
			return blue;
		case 5:
			return purple;
		default:
			return red;
	}
}

// CIRCLE DRAWER
void drawCircle(Mat image) {
	circle(image, getRandomPositionPoint(), getRandomRadius(), getRandomColor(), -1);
}

// ELLIPSE DRAWER
void drawEllipse(Mat image) {
	ellipse(image, getRandomPositionPoint(), Size(100, 50), 0, 0, 360, getRandomColor(), -1);
}

// RECTANGLE DRAWER
void drawRectangle(Mat image) {
	rectangle(image, getRandomPositionPoint(), getRandomPositionPoint(), getRandomColor(), -1);
}

// TRIANGLE DRAWER
void drawTriangle(Mat image) {
	Point triangle[1][3] = { {getRandomPositionPoint(), getRandomPositionPoint(), getRandomPositionPoint()} };

	const Point* ppt[1] = { triangle[0] };
	const int npt[] = { 3 };

	fillPoly(image, ppt, npt, 1, getRandomColor());
}

// LINE DRAWER
void drawLine(Mat image) {
	line(image, getRandomPositionPoint(), getRandomPositionPoint(), getRandomColor(), 2);
}

// GET SHAPE TYPE ENUM BASED OFF ARGUMENT
ShapeType getEnumShapeType(const string& argument) {
	if (argument == "circle") {
		return CIRCLE;
	} else if (argument == "ellipse") {
		return ELLIPSE;
	} else if (argument == "rectangle") {
		return RECTANGLE;
	} else if (argument == "triangle") {
		return TRIANGLE;
	} else if (argument == "line") {
		return LINE;
	}
	return CIRCLE;
}

// TRIGGER CORRECT DRAW FUNCTION BASED OFF ENUM
void drawShapeWithEnum(Mat image, const ShapeType& shapeTypeEnum) {
	switch (shapeTypeEnum) {
		case CIRCLE:
			drawCircle(image);
			break;
		case ELLIPSE:
			drawEllipse(image);
			break;
		case RECTANGLE:
			drawRectangle(image);	
			break;
		case TRIANGLE:
			drawTriangle(image);
			break;
		case LINE:
			drawLine(image);
			break;
		default:
			cout << "Something went wrong! Could not find enum! Going to draw circle instead." << endl;
			drawCircle(image);
			break;
	}
}

// ON INITIALIZATION, CAPTURE ARGUMENTS AND START SHAPES
int main(int argumentCount, char* arguments[]) {
	if (argumentCount <= 1) {
		cout << "Please enter a shape to draw! (circle, ellipse, rectangle, triangle, line)" << endl;
		return 0;
	}

	// SET RANDOM SEED GENERATOR BY CURRENT TIME
	srand(time(0));

	// MAKE WHITE IMAGE AND ITERATE THROUGH ARGUMENTS
	Mat image = Mat(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3, Scalar(255, 255, 255));
	for (char** argPtr = arguments + 1; argPtr < arguments + argumentCount; ++argPtr) {
		const string argument = toLowerCase(*argPtr);
		const ShapeType shapeTypeEnum = getEnumShapeType(argument);

		// TRIGGER INVOKER WITH ENUM TO START DRAWING SHAPES
		cout << "Drawing shape: " << argument << endl;
		drawShapeWithEnum(image, shapeTypeEnum);
		imshow("Shapes", image);
		waitKey(1500);
	}

	// MAKE A LOOP
	waitKey(0);
	destroyAllWindows();

	// END PROGRAM
	return 0;
}
