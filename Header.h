#pragma once
namespace global {
    extern int index;
}

class PhoneBook {
private:
    char* firstName;
    char* middleName;
    char* lastName;
    char* workPhone;
    char* mobilePhone;

public:
    PhoneBook();
    void AskInformation();
    void Add(PhoneBook* user, int amount);
    bool CheckPhone(char* checkPhone);
    void AddToFile(const char* filename, PhoneBook* user);
    void ShowPersonalData(const char* filename, PhoneBook* user);
    PhoneBook* DeletePerson(PhoneBook* user);
    void GetUser(PhoneBook* user, int i);
    void FindFullName(PhoneBook* user);
    ~PhoneBook();

};