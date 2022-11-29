#include "OfficeEmployee.h"
#include "Worker.h"

int main()
{
    OfficeEmployee oe1;
    oe1.Input();
    oe1.Output();
    cout << "Office Employee 1 salary is: " << oe1.Salary() << endl;
    OfficeEmployee oe2(12, "Tung Lam", "2021/25/4 QL1A", "1/1/2021", 30, 250000);
    oe2.Output();
    cout.setf(ios::fixed);
    cout << setprecision(0) << "Office Employee 2 salary is: " << oe2.Salary() << endl;

    Worker w1;
    w1.Input();
    w1.Output();
    cout << "Worker 1 salary is: " << w1.Salary() << endl;
    Worker w2(26, "Superman", "101 Duong so 7", "10/2/2020", 1000, 100000);
    w2.Output();
    cout << setprecision(0) << "Worker 2 salary is: " << w2.Salary() << endl;

    return 0;
}