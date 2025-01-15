#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;

unsigned int choice = 0;
vector<string> options = {
	"Hobbies",
	"Family",
	"Favorite Show",
	"Favorite Music",
	"Favorite Food"
};

vector<string> imageNames = {
	"hobbies.jpg",
	"family.jpg",
	"favoriteshow.jpg",
	"favoritemusic.jpg",
	"favoritefood.jpg"
};

vector<string> descriptions = {
	"I really like to go workout at the gym! I mostly do weights because cardio is already covered at work. I also enjoy coding in my freetime, video games, as well as hitting the range!",
	"My parents are from Peru while me and my sister are from the US! Among the picture are also my cousins, uncle, grandpa, grandma and two aunts!",
	"My favorite show is The Rookie! They are currently on Season 7 and I am excited to watch new episodes as they drop.",
	"I really enjoy listening to Oh Caroline by The 1975. My favorite genres are usually songs like this, rock and country.",
	"My favorite food is from Peruvian culture. This is called Lomo Saltado."
};

// IMAGE SHOW FUNCTION
static void showImage(const String& pictureName) {
	Mat image = imread(pictureName, IMREAD_COLOR);
	if (!image.data) {
		cout << "Could not open or find the image " << pictureName << endl;
		return;
	}

	// OPEN WINDOW FOR IMAGE
	namedWindow("PicWindow", WINDOW_AUTOSIZE);
	imshow("PicWindow", image);
	waitKey(0);
}

// EXECUTED UPON RUN
int main() {
	cout << "Hello! I am Alex and you may choose any of the options below to learn more about me!" << endl;

    // LOOP FOR MENU AND USER INPUT
    while (true) {
        for (int i = 0; i < options.size(); i++) {
            string option = options[i];
            if (!option.empty()) {
                cout << (i + 1) << ". " << option << endl;
            }
        }

        // ASK FOR USER INPUT WITH CHOICE OF EXITING
        cout << "Please enter the number of the option (0 to exit): ";
        cin >> choice;

        // IF THE USER WOULD LIKE TO EXIT, THEN BREAK AND END THE PROGRAM
        if (choice <= 0) {
            break;
        }

        // ENSURE THE INPUT IS VALID
		int arrayIndex = choice - 1;
		if ((choice >= 1 && choice <= options.size()) && (!imageNames[arrayIndex].empty() && !descriptions[arrayIndex].empty())) {
            cout << descriptions[arrayIndex] << endl;
			showImage(imageNames[arrayIndex]);
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
