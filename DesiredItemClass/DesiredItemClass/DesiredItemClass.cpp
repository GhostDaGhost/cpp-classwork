#include <iostream>
#include "iPhone16.h"
#include <string>

void createPhones() {
    string myFavoriteColor = "Red";

    // MAKE THE FIRST iPHONE
    iPhone16* firstNewPhone = new iPhone16(128, 123456789, myFavoriteColor);
    firstNewPhone->batteryLevel = 100;

    // TRIGGER METHODS
    firstNewPhone->StartUp();
    firstNewPhone->SetStorageGigs(64);
    firstNewPhone->SetPinCode(1234);

    // DESTROY OBJECT
    delete firstNewPhone;

    // MAKE THE SECOND iPHONE
    iPhone16* secondNewPhone = new iPhone16(240, 2719381, myFavoriteColor);
    secondNewPhone->batteryLevel = 75;

    // TRIGGER METHODS
    secondNewPhone->StartUp();
    secondNewPhone->SetPinCode(9999);
    secondNewPhone->ActivateCamera();

    // DESTROY OBJECT
    delete secondNewPhone;

    // MAKE THE THIRD iPHONE (BUT LOCAL THIS TIME)
    iPhone16 thirdNewPhone(32, 1113131, myFavoriteColor);
    thirdNewPhone.batteryLevel = 20;

    // TRIGGER METHODS
    thirdNewPhone.StartUp();
    thirdNewPhone.SetPinCode(1111);
}

int main() {
    createPhones();
    return 0;
}
