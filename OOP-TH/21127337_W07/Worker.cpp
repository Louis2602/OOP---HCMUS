#include "Worker.h"

Worker::Worker(int id, string name, string address, string hireDate, int _noItems, double _payRate) : Employee(id, name, address, hireDate)
{
    noItems = _noItems;
    payRate = _payRate;
}
void Worker::Input()
{
    cout << "INPUT WORKER INFORMATION" << endl;
    Employee::Input();
    cout << "Enter your number of items in a month: ";
    cin >> noItems;
    cout << "Enter your pay rate per item: ";
    cin >> payRate;
}
void Worker::Output()
{
    Employee::Output();
    cout << "Number of items in a month: " << noItems << endl;
    cout << "Pay rate per item: " << payRate << endl;
}
double Worker::Salary()
{
    return payRate * noItems;
}