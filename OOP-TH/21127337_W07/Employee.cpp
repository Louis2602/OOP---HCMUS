#include "Employee.h"

Employee::Employee(int _id, string _name, string _address, string _hireDate)
{
    id = _id;
    name = _name;
    address = _address;
    hireDate = _hireDate;
}
void Employee::Input()
{
    do
    {
        cout << "ID: ";
        cin >> id;
    } while (id <= 0);
    cout << "Name: ";
    cin.ignore(1);
    getline(cin, name);
    cout << "Hire Date: ";
    getline(cin, hireDate);
    cout << "Address: ";
    getline(cin, address);
}

void Employee::Output()
{
    cout << "========INFORMATION========" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Address: " << address << endl;
    cout << "Salary: " << Salary() << endl;
}