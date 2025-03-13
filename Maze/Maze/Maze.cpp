#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <math.h>
#include <queue>
#include <vector>
#include <ctime>

// NAMESPACES
using namespace cv;
using namespace std;

// GLOBAL CONSTANTS
const char wndname[] = "Maze";
const unsigned int DELAY = 1;
const unsigned int END_AFTER_MS = 3000;

const Scalar BLACK(0, 0, 0);
const Scalar WHITE(255, 255, 255);

const Mat image = Mat::zeros(500, 500, CV_8UC3);
enum Side { Top, Bottom, Left, Right };
const int dirX[4] = { -1, -1, 0, 0 };
const int dirY[4] = { 0, 0, 1, -1 };

const unsigned int totalRows = 3;
const unsigned int totalColumns = 5;
const unsigned int sizeOfSquare = 50;
const bool IS_IN_PART_1 = true;

// SIDES STRUCTURE
struct Sides {
    bool Top;
    bool Bottom;
    bool Left;
    bool Right;
};

// IMAGE REFRESH
void displayImageWindow() {
    imshow(wndname, image);
    waitKey(DELAY);
}

// SHAPE OBJECT
class Shape {
    protected:
        int _x; int _y; int _size;
    public:
        virtual void Draw() = 0;
        Shape(int x, int y, int size = 0) {
            _x = x; _y = y; _size = size;
        }

        int getX() { return _x; }
        int getY() { return _y; }
        int getSize() { return _size; }
};

// SQUARE OBJECT
class Square : public Shape {
    public:
        Square(int x, int y, int size) : Shape(x, y, size) {}

        virtual void Draw() {
            rectangle(image, Point(_x, _y), Point(_x + _size, _y + _size), WHITE);
        }
};

// MAZE SQUARE CLASS
class MazeSquare : public Square {
    private:
        bool visited = false;
        bool dequeued = false;
        bool traversed = false;

        Sides sides = { true, true, true, true };
        Point qMarkPosition = Point(_x + _size * 2 / 3, _y + _size / 2);
        Point oMarkPosition = Point(_x + _size / 4, _y + _size / 2);
    public:
        // CONSTRUCTOR
        MazeSquare(int x, int y, int size) : Square(x, y, size) {}

        // METHODS
        void markDequeued() {
            dequeued = true;
            putText(image, "q", qMarkPosition, FONT_HERSHEY_SIMPLEX, 0.5, WHITE, 1);
            displayImageWindow();
        }

        void undequeue() {
            dequeued = false;
            putText(image, "q", qMarkPosition, FONT_HERSHEY_SIMPLEX, 0.5, BLACK, 1);
            displayImageWindow();
        }

        void markVisited() {
            visited = true;
            putText(image, "v", Point(_x + _size / 6, _y + _size / 2), FONT_HERSHEY_SIMPLEX, 0.5, WHITE, 1);
            displayImageWindow();
        }

        void markTraversed() {
            traversed = true;
            putText(image, "o", oMarkPosition, FONT_HERSHEY_SIMPLEX, 0.5, WHITE, 1);
            displayImageWindow();
        }

        void untraverse() {
            traversed = false;
            putText(image, "o", oMarkPosition, FONT_HERSHEY_SIMPLEX, 0.5, BLACK, 1);
            displayImageWindow();
        }

        void removeSide(Side s) {
            switch (s) {
                case Top:
                    sides.Top = false;
                    line(image, Point(_x, _y), Point(_x + _size, _y), BLACK, 2);
                    break;
                case Bottom:
                    sides.Bottom = false;
                    line(image, Point(_x, _y + _size), Point(_x + _size, _y + _size), BLACK, 2);
                    break;
                case Left:
                    sides.Left = false;
                    line(image, Point(_x, _y), Point(_x, _y + _size), BLACK, 2);
                    break;
                case Right:
                    sides.Right = false;
                    line(image, Point(_x + _size, _y), Point(_x + _size, _y + _size), BLACK, 2);
                    break;
            }

            // REFRESH IMAGE
            displayImageWindow();
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
};

// MAZE CLASS
class Maze {
    private:
        vector<vector<MazeSquare*>> grid;
        int num_rows, num_columns;
    public:
        // CONSTRUCTOR
        Maze(int r, int c, int size) : num_rows(r), num_columns(c) {
            grid.resize(num_rows);
            for (int row = 0; row < num_rows; row++) {
                grid[row].resize(num_columns);
                for (int col = 0; col < num_columns; col++) {
                    grid[row][col] = new MazeSquare(col * size, row * size, size);
                }
            }
        }

        // DESTRUCTOR
        ~Maze() {
            for (int row = 0; row < num_rows; row++) {
                for (int col = 0; col < num_columns; col++) {
                    delete grid[row][col];
                }
            }
        }

        // METHODS
        void drawGrid() {
            for (int row = 0; row < num_rows; row++) {
                for (int col = 0; col < num_columns; col++) {
                    Square* squarePtr = grid[row][col];
                    squarePtr->Draw();
                }
            }
        }

        void randomTraversing() {
            queue<MazeSquare*> sqPtrs;

            // RANDOMLY SELECT SQUARES
            const unsigned int num_of_iterations = num_rows * num_columns * 2;
            for (int i = 0; i < num_of_iterations; i++) {
                sqPtrs.push(grid[rand() % num_rows][rand() % num_columns]);
            }

            // REPEAT UNTIL QUEUE IS EMPTY
            while (!sqPtrs.empty()) {
                MazeSquare* sqPtr = sqPtrs.front();
                sqPtrs.pop();

                // MARK SQUARE AS DEQUEUED
                sqPtr->markDequeued();
                waitKey(500);

                // INITIALIZE NEIGHBOR SQUARES VECTOR AND SIDES VECTOR
                vector<MazeSquare*> neighborSquarePtrs;
                vector<Side> directions;

                // FIND NEIGHBORS
                for (int i = 0; i < 4; i++) {
                    const int newRowPos = (sqPtr->getY() / sizeOfSquare) + dirX[i];
                    const int newColPos = (sqPtr->getX() / sizeOfSquare) + dirY[i];

                    // CHECK IF THE NEW POSITION IS VALID
                    if (newRowPos >= 0 && newRowPos < num_rows && newColPos >= 0 && newColPos < num_columns) {
                        //cout << "Found a neighbor at " << newRowPos << ", " << newColPos << endl;
                        MazeSquare* neighborSquarePtr = grid[newRowPos][newColPos];
                        if (!neighborSquarePtr->isVisited()) {
                            neighborSquarePtrs.push_back(neighborSquarePtr);
                            directions.push_back(static_cast<Side>(i));
                        }
                    }
                }

                // IF WE FOUND NEIGHBORS, MARK THEM AS VISITED
                if (!neighborSquarePtrs.empty()) {
                    const int r = rand() % neighborSquarePtrs.size();
                    MazeSquare* neighborSquarePtr = neighborSquarePtrs[r];
                    neighborSquarePtr->markVisited();

					// REMOVE SIDE BETWEEN THE TWO SQUARES
                    switch (directions[r]) {
                        case Top:
                        case Bottom:
                            sqPtr->removeSide(Top);
                            neighborSquarePtr->removeSide(Bottom);
                            break;
                        case Left:
                            sqPtr->removeSide(Right);
                            neighborSquarePtr->removeSide(Left);
                            break;
                        case Right:
                            sqPtr->removeSide(Left);
                            neighborSquarePtr->removeSide(Right);
                            break;
                    }
                }

                // REMOVE THE Q MARK FROM THE DEQUEUED SQUARE
                waitKey(1000);
                sqPtr->undequeue();
            }
        }

        void prepareMazeForSolving() {
            MazeSquare* startingSquare = grid[0][0];
            MazeSquare* endingSquare = grid[num_rows - 1][num_columns - 1];

            // REMOVE ENTRANCE AND EXIT SIDES OF FIRST AND LAST SQUARES
            startingSquare->removeSide(Left);
            endingSquare->removeSide(Right);

            // CREATE QUEUE AND INSERT STARTING SQUARE
            queue<MazeSquare*> adjoiningSquares;
            adjoiningSquares.push(startingSquare);

            // MARK STARTING SQUARE AS VISITED AND GO THROUGH QUEUE UNTIL EMPTY
            startingSquare->markVisited();
            while (!adjoiningSquares.empty()) {
                //
            }
        }
};

// MAIN FUNCTION
int main() {
    srand(/*time(0)*/ 100);
    displayImageWindow();

    // CREATE MAZE
    Maze maze(totalRows, totalColumns, sizeOfSquare);
    maze.drawGrid();
    if (IS_IN_PART_1) {
        maze.randomTraversing();
    } else {
        maze.prepareMazeForSolving();
    }

    // END PROGRAM
    waitKey(END_AFTER_MS);
}
