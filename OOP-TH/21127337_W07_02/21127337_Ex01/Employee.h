#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee
{
protected:
    int id = -1;
    string name = "unknown";
    string address = "unknown";
    string hireDate = "unknown";

public:
    Employee(){};
    Employee(int id);
    Employee(int id, string name);
    Employee(int id, string name, string address);
    Employee(int id, string name, string address, string hireDate);
    virtual void Input();
    virtual void Output();
    virtual double Salary() = 0;
};