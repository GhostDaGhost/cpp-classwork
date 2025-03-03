#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <math.h>

// INCLUDES THAT WE NEED FOR MAZE
#include <queue>
#include <vector>
#include <ctime>

// NAMESPACES
using namespace cv;
using namespace std;

// DEFINES
#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

// GLOBAL VARIABLES
char wndname[] = "TurtleWindow";
Mat image = Mat::zeros(500, 500, CV_8UC3);
Scalar WHITE(255, 255, 255);
const int DELAY = 1;
Point _curPosition(250, 250);
int _direction = 0;

// 
// Must be called in main() before any other drawing function
//
void init() {
    imshow(wndname, image);
    waitKey(DELAY);
}

//
// Move the pen to the given coordinates without leaving a mark
// 
// Note (0,0)     refers to the upper left corner
//      (500,500) refers to the bottom right corner  
//
void changePosition(int x, int y) {
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
void changeDirection(int direction) {
    _direction = direction;
}

//
// Moves the pen forward the given number of pixels
// Note leaves a mark creating a line from the previous point
// to the new point
//
void moveForward(int nPixels) {
    int x = static_cast<int>(round(nPixels * cos(degToRad(_direction))));
    int y = static_cast<int>(round(nPixels * sin(degToRad(_direction))));

    Point newPoint = Point(x + _curPosition.x, y + _curPosition.y);
    line(image, _curPosition, newPoint, WHITE);
    _curPosition = newPoint;
    // cout << "moved to " << newPoint.x << "," << newPoint.y << " dir:" << _direction << endl;
    imshow(wndname, image);
    waitKey(DELAY);
}

class Shape {
    public:
        virtual void Draw() = 0;

        Shape(int x, int y, int size = 0) {
            _x = x;
            _y = y;
            _size = size;
        }

        int getX() {
            return _x;
        }

        int getY() {
            return _y;
        }
    protected:
        int _x;
        int _y;
        int _size;
};

class Square : public Shape {
    public:
        Square(int x, int y, int size) : Shape(x, y, size) {}

        virtual void Draw() {
            changePosition(_x, _y);

            int myDirection = 0;
            changeDirection(myDirection);
            for (int i = 0; i < 4; i++) {
                moveForward(_size);
                myDirection += 90;
                changeDirection(myDirection);
            }
        }
};

/****************
    MAZE CODE
****************/
struct Sides {
    bool Top;
    bool Bottom;
    bool Left;
    bool Right;
};

enum Side { Top, Bottom, Left, Right };

// MAZE SQUARE CLASS
class MazeSquare : public Square {
    private:
        bool visited = false;
        bool dequeued = false;
        Sides sides = { true, true, true, true };
    public:
        // CONSTRUCTOR
        MazeSquare(int x, int y, int size) : Square(x, y, size) {}

        // METHODS
        void removeSide(Side s) {
            switch (s) {
                case Top:
                    sides.Top = false;
                    break;
                case Bottom:
                    sides.Bottom = false;
                    break;
                case Left:
                    sides.Left = false;
                    break;
                case Right:
                    sides.Right = false;
                    break;
            }
        }

        void markVisited() {
            visited = true;
            Draw();
        }

        void markDequeued() {
            dequeued = true;
            Draw();
        }

        bool isVisited() {
            return visited;
        }

        bool hasTop() {
            return sides.Top;
        }

		bool hasBottom() {
			return sides.Bottom;
		}

		bool hasLeft() {
			return sides.Left;
		}

		bool hasRight() {
			return sides.Right;
		}

        virtual void Draw() {
            changePosition(_x, _y);
            if (sides.Top) {
                moveForward(_size);
            }

            changeDirection(90);
            if (sides.Right) {
                moveForward(_size);
            }

            changeDirection(180);
            if (sides.Bottom) {
                moveForward(_size);
            }

            changeDirection(270);
            if (sides.Left) {
                moveForward(_size);
            }

            // IF VISITED, PUT TEXT OF "V" TO MARK AS VISITED
            if (visited) {
                changePosition(_x + _size / 4, _y + _size / 2);
                putText(image, "v", Point(_x + _size / 4, _y + _size / 2), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);
            }
            
            // IF DEQUEUED, PUT TEXT OF "Q" TO MARK AS DEQUEUED
            if (dequeued) {
                changePosition(_x + 3 * _size / 4, _y + _size / 2);
                putText(image, "q", Point(_x + 3 * _size / 4, _y + _size / 2), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);
            }
        }
};

// MAZE CLASS
class Maze {
    private:

    public:

};

// MAIN FUNCTION
int main() {
    srand(time(0));

    // CREATE MAZE


    // WAIT 10 SECONDS BEFORE CLOSING PROGRAM
    waitKey(10000);
    return 0;
}
