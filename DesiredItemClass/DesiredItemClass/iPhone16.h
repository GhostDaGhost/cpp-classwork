#include <iostream>
#include <string>

using namespace std;

class iPhone16 {
    private:
        unsigned int storageGigs;
        long serialNumber;
        unsigned int pinCode;
        bool isVPNOn;

    public:
        unsigned int batteryLevel;
        bool isCharging;
        bool isWifiOn;
        string color;

        // CONSTRUCTOR
        iPhone16(int newStorageGigs, long newSerialNumber, string newColor) {
            cout << "Constructor triggered for iPhone 16 (Serial: " << newSerialNumber << " | Color: " << newColor << ")" << endl;

            // INITIALIZE MEMBERS
            storageGigs = newStorageGigs;
            serialNumber = newSerialNumber;
            color = newColor;
        }

        // DESTRUCTOR
        ~iPhone16() {
            cout << "Destructor triggered for iPhone 16 (Serial: " << serialNumber << " | Color: " << color << ")" << endl;
        }

        void StartUp() {
            cout << "Welcome to iPhone!" << endl;
        }

        int GetStorageGigs() {
            return storageGigs;
        }

        void SetStorageGigs(int newNum) {
            storageGigs = newNum;
        }

        int GetSerialNumber() {
            return serialNumber;
        }

        void SetPinCode(int newPinCode) {
            pinCode = newPinCode;
        }

        void ActivateCamera() {
            cout << "Let's activate camera for this iPhone!" << endl;
        }

        bool IsVPNEnabled() {
            return isVPNOn;
        }
};
