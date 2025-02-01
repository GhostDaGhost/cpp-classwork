#include <iostream>
#include <opencv2/opencv.hpp>

// NAMESPACES
using namespace cv;
using namespace std;

// DEFINES
constexpr auto WINDOW_WIDTH = 500;;
constexpr auto WINDOW_HEIGHT = 500;;

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

// CIRCLE DRAWER
void drawCircle(Mat image) {
	circle(image, Point(250, 100), 50, red, -1);
}

// ELLIPSE DRAWER
void drawEllipse(Mat image) {
	ellipse(image, Point(250, 400), Size(100, 50), 0, 0, 360, purple, -1);
}

// RECTANGLE DRAWER
void drawRectangle(Mat image) {
	rectangle(image, Point(50, 50), Point(150, 150), green, -1);
}

// TRIANGLE DRAWER
void drawTriangle(Mat image) {
	Point triangle[1][3] = { {Point(350, 50), Point(300, 150), Point(400, 150)} };

	const Point* ppt[1] = { triangle[0] };
	const int npt[] = { 3 };

	fillPoly(image, ppt, npt, 1, blue);
}

// LINE DRAWER
void drawLine(Mat image) {
	line(image, Point(50, 300), Point(450, 300), black, 2);
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

	// MAKE WHITE IMAGE AND ITERATE THROUGH ARGUMENTS
	Mat image = Mat(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3, Scalar(255, 255, 255));
	for (int i = 0; i < argumentCount; i++) {
		const string argument = toLowerCase(arguments[i]);
		const ShapeType shapeTypeEnum = getEnumShapeType(argument);

		// TRIGGER INVOKER WITH ENUM TO START DRAWING SHAPES
		drawShapeWithEnum(image, shapeTypeEnum);
		imshow("Shapes", image);
		waitKey(2000);
	}

	// MAKE A LOOP
	waitKey(0);
	destroyAllWindows();

	// END PROGRAM
	return 0;
}
