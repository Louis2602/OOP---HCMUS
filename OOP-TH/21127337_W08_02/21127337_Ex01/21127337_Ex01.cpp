#include "OfficeEmployee.h"
#include "Worker.h"
#include "Employee.h"
#include "Company.h"

int main()
{
    cout.setf(ios::fixed);
    cout << setprecision(0);
    // OfficeEmployee oe1;
    // oe1.Input();
    // oe1.Output();
    // cout << "Office Employee 1 salary is: " << oe1.Salary() << endl;

    // OfficeEmployee oe2(12, "Tung Lam", "2021/25/4 QL1A", "1/1/2021", 30);
    // oe2.Output();
    // cout << "Office Employee 2 salary is: " << oe2.Salary() << endl;

    // OfficeEmployee oe3(12, 30);
    // oe3.Output();

    // cout << "Office Employee 3 salary is: " << oe3.Salary() << endl;

    // OfficeEmployee oe4(12, "Bui Minh", 30);
    // oe3.Output();

    // cout << "Office Employee 3 salary is: " << oe4.Salary() << endl;

    // OfficeEmployee oe5(12, "Tran Kha", "101 Duong so 7", 30);
    // oe5.Output();

    // cout << "Office Employee 5 salary is: " << oe5.Salary() << endl;

    // Worker w1;
    // w1.Input();
    // w1.Output();
    // cout << "Worker 1 salary is: " << w1.Salary() << endl;

    // Worker w2(26, "Superman", "101 Duong so 7", "10/2/2020", 1000);
    // w2.Output();
    // cout << "Worker 2 salary is: " << w2.Salary() << endl;

    // Worker w3(13, 50);
    // w3.Output();
    // cout << "Worker 3 salary is: " << w3.Salary() << endl;

    // Worker w4(13, "Ngan Lam", 123);
    // w4.Output();
    // cout << "Worker 4 salary is: " << w4.Salary() << endl;

    // Worker w5(13, "Kim", "2012/12/3 Tran Hung Dao", 156);
    // w5.Output();
    // cout << "Worker 5 salary is: " << w5.Salary() << endl;
    // Employee *e;
    // e = &oe1;
    // e->Output();

    // e = &w2;
    // e->Output();

    Company comp;
    comp.Input();
    comp.employeeInfo();
    cout << "=============================\n";
    comp.totalSalary();
    comp.highestSalary();
    return 0;
}