#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee
{
protected:
    int id;
    string name;
    string address;
    string hireDate;

public:
    Employee(){};
    Employee(int id, string name, string address, string hireDate);
    virtual void Input();
    virtual void Output();
    virtual double Salary() = 0;
};