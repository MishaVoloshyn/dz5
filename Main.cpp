#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <iostream>
#include <cstring>

using namespace std;

void ShowMenu() {
    cout << "1 - Add " << endl;
    cout << "2 - Show" << endl;
    cout << "3 - Delete " << endl;
    cout << "4 - Find  full name" << endl;
    cout << "5 - Exit" << endl;
}

int main() {

    int size_user = 20;
    setlocale(LC_ALL, "");
    PhoneBook* user = new PhoneBook[size_user];
    const char* filename = "users.txt";
    bool repeat = false;
    int userAction;
    do {
        ShowMenu();
        cout << "your answer: ";
        cin >> userAction;
        switch (userAction) {
        case 1:
            int amount;
            cout << "Enter amount: ";
            cin >> amount;
            user->Add(user, amount);    //function to get data about employee(s)
            user->AddToFile(filename, user);    //function to write data to a file
            break;
        case 2:
            user->ShowPersonalData(filename, user);
            break;
        case 3:
            user->DeletePerson(user);
            user->AddToFile(filename, user);
            break;
        case 4:
            user->FindFullName(user);
            break;
        case 5:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Incorrect choice, try again" << endl;
            cout << endl;
            break;
        }
        if (userAction == 5) {
            break;
        }
        else {
            cout << "Continue?\n[1] - yes\t[0] - no" << endl;
            cout << endl;
            cout << "(your answer): ";
            cin >> repeat;
        }

    } while (repeat);
    user->~PhoneBook();

}