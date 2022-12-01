#include "Worker.h"

Worker::Worker(int id, int _noItems) : Employee(id)
{
    noItems = _noItems;
}
Worker::Worker(int id, string name, int _noItems) : Employee(id, name)
{
    noItems = _noItems;
}

Worker::Worker(int id, string name, string address, int _noItems) : Employee(id, name, address)
{
    noItems = _noItems;
}
Worker::Worker(int id, string name, string address, string hireDate, int _noItems) : Employee(id, name, address, hireDate)
{
    noItems = _noItems;
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
}
double Worker::Salary()
{
    return payRate * noItems;
}