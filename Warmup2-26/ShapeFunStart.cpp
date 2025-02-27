// ShapeFun.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;

#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

char wndname[] = "TurtleWindow";
Mat image = Mat::zeros(500, 500, CV_8UC3);
Scalar WHITE(255, 255, 255);
const int DELAY = 1;
Point _curPosition(250, 250);
int _direction = 0;


// 
// Must be called in main() before any other drawing function
//
void init()
{
	imshow(wndname, image);
	waitKey(DELAY);
}

//
// Move the pen to the given coordinates without leaving a mark
// 
// Note (0,0)     refers to the upper left corner
//      (500,500) refers to the bottom right corner  
//
void changePosition(int x, int y)
{
	_curPosition.x = x;
	_curPosition.y = y;
}

//
// point in the direction given in degrees
// 0   ==> point right
// 90  ==> point down
// 180 ==> point left
// 270 ==> point up
//
void changeDirection(int direction)
{
	_direction = direction;
}

//
// Moves the pen forward the given number of pixels
// Note leaves a mark creating a line from the previous point
// to the new point
//
void moveForward(int nPixels)
{
	int x = static_cast<int>(round(nPixels * cos(degToRad(_direction))));
	int y = static_cast<int>(round(nPixels * sin(degToRad(_direction))));

	Point newPoint = Point(x + _curPosition.x, y + _curPosition.y);
	line(image, _curPosition, newPoint, WHITE);
	_curPosition = newPoint;
	// cout << "moved to " << newPoint.x << "," << newPoint.y << " dir:" << _direction << endl;
	imshow(wndname, image);
	waitKey(DELAY);
}

/*void main()
{
	init();
	changePosition(200, 200);
	int direction = 0;
	for (int i = 0; i < 4; i++)
	{
		changeDirection(direction);
		moveForward(100);
		direction += 90;
	}
	waitKey(10000);
}*/

//#if FULL_DAILY_ASSIGNMENT  // remove this line for the full daily assignment

class Shape
{
public:
	virtual void Draw() = 0;

	Shape(int x, int y, int size = 0)
	{
		_x = x;
		_y = y;
		_size = size;
	}
protected:
	int _x;
	int _y;
	int _size;
};

class Square : public Shape
{
public:
	Square(int x, int y, int size) : Shape(x, y, size) {}

	virtual void Draw()
	{
		changePosition(_x, _y);
		int myDirection = 0;
		changeDirection(myDirection);
		for (int i = 0; i < 4; i++)
		{
			moveForward(_size);
			myDirection += 90;
			changeDirection(myDirection);
		}
	}
};

/* Add a Pentagon and a Star classes that inherit from the public shape base class */
class Pentagon : public Shape {
	public:
		Pentagon(int x, int y, int size) : Shape(x, y, size) {}

		virtual void Draw() {
			changePosition(_x, _y);

			int myDirection = 0;
			changeDirection(myDirection);
			for (int i = 0; i < 6; i++) {
				moveForward(_size);
				myDirection += 72;
				changeDirection(myDirection);
			}
		}
};

class Star : public Shape {
	public:
		Star(int x, int y, int size) : Shape(x, y, size) {}

		virtual void Draw() {
			changePosition(_x, _y);

			int myDirection = 0;
			changeDirection(myDirection);
			for (int i = 0; i < 5; i++) {
				moveForward(_size);
				myDirection += 144;
				changeDirection(myDirection);
			}
		}
};

void drawShapes(Shape* shapeArr[3])
{
	for (int i = 0; i < 3; i++)
		(shapeArr[i])->Draw();
}

int main()
{
	cout << "Test" << endl;
	init();

	Shape* myShapes[3] = {
		new Square(200, 200, 50),
		new Pentagon(100, 100, 75),
		new Star(300,300,100)
	};

	drawShapes(myShapes);
	waitKey(10000);
}

//#endif // remove this line for the full daily assignment
