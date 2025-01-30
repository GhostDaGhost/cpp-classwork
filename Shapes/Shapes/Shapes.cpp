#include <iostream>
#include <opencv2/opencv.hpp>

// NAMESPACES
using namespace cv;
using namespace std;

// DEFINE COLORS
Scalar black(0, 0, 0);
Scalar red(0, 0, 255);
Scalar green(0, 255, 0);
Scalar blue(255, 0, 0);
Scalar purple(255, 0, 255);

// ON INITIALIZATION, CAPTURE ARGUMENTS AND START SHAPES
int main(int argumentCount, char* arguments[]) {
	const int width = 500, height = 500;
	Mat image = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));

	// DEBUG CIRCLE
	circle(image, cv::Point(250, 100), 50, red, -1);

	// ITERATE THROUGH ARGUMENTS
	/*for (int i = 0; i < argumentCount; i++) {
		//
	}*/

	// DISPLAY IMAGE AND WAIT FOR KEYPRESS TO DESTROY WINDOWS
	imshow("Shapes", image);
	waitKey(0);
	destroyAllWindows();

	// END PROGRAM
	return 0;
}
