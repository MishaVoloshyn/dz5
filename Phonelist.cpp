#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
const int MAX = 20;


errno_t code;

PhoneBook::PhoneBook() {
    firstName = nullptr;
    middleName = nullptr;
    lastName = nullptr;

    workPhone = nullptr;
    mobilePhone = nullptr;
}

//function to check phone
bool PhoneBook::CheckPhone(char* checkPhone) {
    int size = 0;
    while (checkPhone[size] != '\0')
    {
        if (!isdigit(checkPhone[size]))
        {
            return false;
        }
        size++;
    }

    if (size == 10)
    {
        return true;
    }
    else {
        return false;
    }

}

//function to ask information about user
void PhoneBook::AskInformation() {
    if (global::index < MAX) {
        //full name 

        char buffFirstName[20], buffMiddleName[20], buffLastName[20];
        cout << "Name: ";
        cin >> buffFirstName;
        firstName = new char[strlen(buffFirstName) + 1];
        strcpy(firstName, buffFirstName);

        cout << "Surname: ";
        cin >> buffMiddleName;
        middleName = new char[strlen(buffMiddleName) + 1];
        strcpy(middleName, buffMiddleName);

        cout << "Last Name: ";
        cin >> buffLastName;
        lastName = new char[strlen(buffLastName) + 1];
        strcpy(lastName, buffLastName);


        
        char buffWorkPhone[12];
        while (!CheckPhone(buffWorkPhone)) {
            cout << "Work  number (for exp. 012 345 67 89): ";
            cin >> buffWorkPhone;
        }
        workPhone = new char[strlen(buffWorkPhone) + 1];
        strcpy(workPhone, buffWorkPhone);

        
        char buffMobPhone[12];
        while (!CheckPhone(buffMobPhone)) {
            cout << "Mobile  number (for exp. 012 345 67 89): ";
            cin >> buffMobPhone;
        }
        mobilePhone = new char[strlen(buffMobPhone) + 1];
        strcpy(mobilePhone, buffMobPhone);
        (global::index)++;
    }
    else {
        cout << "List full" << endl;
    }
}

void PhoneBook::Add(PhoneBook* user, int amount) {
    for (int i = 0; i < amount; i++) {
        user[i].AskInformation();
    }
}

void PhoneBook::AddToFile(const char* filename, PhoneBook* user) {
    FILE* users;
    users = fopen(filename, "w");
    if (users == 0)
    {
        cout << "Error opening file\n";
    }
    else
    {
        for (int i = 0; i < global::index; i++) {
            fprintf(users, "FIO: %s %s %s \n", user[i].firstName, user[i].middleName, user[i].lastName);
            fprintf(users, "Work phone number: %s \n", user[i].workPhone);
            fprintf(users, "Mobile phone number: %s \n\n", user[i].mobilePhone);
        }
        cout << "Data saved! " << endl;
        fclose(users);
        printf("User data loaded to file successfully!\n");
    }
}

PhoneBook* PhoneBook::DeletePerson(PhoneBook* user) {
    char buffMiddleName[20];
    int userIndex = -1;
    cout << "Enter user`s middleName: ";
    cin >> buffMiddleName;


    for (int i = 0; i < global::index; i++) {
        if (strcmp(user[i].middleName, buffMiddleName) == 0)
        {
            userIndex = i;
            break;
        }
    }
    int new_size = 5;
    PhoneBook* new_users = new PhoneBook[new_size];
    int j = 0;
    for (int i = 0; i < global::index - 1; i++) {
        if (userIndex != -1) {
            //name
            new_users[j].firstName = new char[strlen(user[i].firstName) + 1];
            strcpy(new_users[j].firstName, user[i].firstName);
            //middle name
            new_users[j].middleName = new char[strlen(user[i].middleName) + 1];
            strcpy(new_users[j].middleName, user[i].middleName);
            //last name
            new_users[j].lastName = new char[strlen(user[i].lastName) + 1];
            strcpy(new_users[j].lastName, user[i].lastName);

            //work phone
            new_users[j].workPhone = new char[strlen(user[i].workPhone) + 1];
            strcpy(new_users[j].workPhone, user[i].workPhone);
            //mobile phone
            new_users[j].mobilePhone = new char[strlen(user[i].mobilePhone) + 1];
            strcpy(new_users[j].mobilePhone, user[i].mobilePhone);
            j++;
        }
    }
    delete[] user;
    cout << "Data deleted successfully" << endl;
    return new_users;
}

void PhoneBook::ShowPersonalData(const char* filename, PhoneBook* user) {
    FILE* users;
    code = fopen_s(&users, filename, "r");
    if (!code)
    {
        char buff;
        while ((buff = fgetc(users)) != EOF)
            cout << buff;
    }
    else {
        cout << "Something went wrong :(" << endl;
    }
    fclose(users);
}

void PhoneBook::GetUser(PhoneBook* user, int i) {
    cout << "FIO: " << user[i].firstName << "\t" << user[i].middleName << "\t" << user[i].lastName << endl;
    cout << "Work number: " << user[i].workPhone << endl;
    cout << "Mobile number: " << user[i].mobilePhone << endl;
}

void PhoneBook::FindFullName(PhoneBook* user) {
    if (global::index == 0)
    {
        cout << "List is empty!" << endl;
    }
    else {
        char buffName[20], buffMiddle[20], buffLast[20];
        bool check = false;
        cout << "Enter FIO: ";
        cout << "Name: ";
        cin >> buffName;
        cout << "\tSurname: ";
        cin >> buffMiddle;
        cout << "\tLast name: ";
        cin >> buffLast;
        cout << endl;

        for (int i = 0; i < global::index; i++) {
            if ((strcmp(user[i].firstName, buffName) == 0) || (strcmp(user[i].middleName, buffMiddle) == 0) || (strcmp(user[i].lastName, buffLast) == 0)) {
                check = true;
                user[i].GetUser(user, i);
            }
        }
        if (!check) {
            cout << "Incorrect FIO" << endl;
        }
    }


}

PhoneBook::~PhoneBook() {
    delete[] firstName;
    delete[] middleName;
    delete[] lastName;
    delete[] mobilePhone;
    delete[] workPhone;
}