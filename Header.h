#pragma once
namespace global {
    extern int index;
}

class PhoneList {
private:
    char* firstName;
    char* middleName;
    char* lastName;
    char* workPhone;
    char* mobilePhone;

public:
    PhoneList();
    void AskInformation();
    void Add(PhoneList* user, int amount);
    bool CheckPhone(char* checkPhone);
    void AddToFile(const char* filename, PhoneList* user);
    void ShowPersonalData(const char* filename, PhoneList* user);
    PhoneList* DeletePerson(PhoneList* user);
    void GetUser(PhoneList* user, int i);
    void FindFullName(PhoneList* user);
    ~PhoneList();

};