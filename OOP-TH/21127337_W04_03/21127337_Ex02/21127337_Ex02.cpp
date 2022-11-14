#include "Triangle.h"
#include "TriangleArray.h"

int main()
{
    // Point a;
    // a.Output();
    Point b(3);
    // b.Output();
    Point c(3, 5);
    // c.Output();
    Point d("(3,11)");
    // d.Output();
    // Point e;
    // e.loadPoint("load.txt");
    // e.Output();
    // e.savePoint("save.txt");
    // cout << "Distance: " << c.DistanceAB(d);

    Triangle a1;
    cout << "Default Constructor:\n";
    a1.Output();
    Triangle b1(1, 1, 2, 3, 3, 5);
    cout << "6-double Constructor:\n";
    b1.Output();
    Triangle c1(b, c, d);
    cout << "3-Points Constructor:\n";
    c1.Output();
    Triangle d1("(0,0)(0,1)(1,0)");
    cout << "String Constructor:\n";
    d1.Output();
    // Triangle e1;
    // e1.Input();
    // e1.Output();
    // b1.isValidTriangle() == true ? cout << "Valid Triangle\n" : cout << "Invalid Triangle\n";
    // cout << "Type of triangle: ";
    // int i = b1.TypeOfTriangle();
    // if (i == 1)
    //     cout << "Right-angled Isosceles triangle";
    // cout << "Chu vi = " << b1.Parameter() << endl;
    // cout << "Dien tich = " << b1.Area() << endl;

    // Triangle f;
    // f.loadTriangle("load.txt");
    // f.Output();
    // f.saveTriangle("save.txt");

    // TriangleArray w(5);
    // cout << "N unit triangles:\n";
    // w.Output();
    // Triangle test[4] = {a1, b1, c1, d1};
    // TriangleArray q(test, 4);
    // cout << "Contrustor with triangles array:\n";
    // q.Output();
    // vector<Triangle> vTA = {a1, b1, c1};
    // TriangleArray q1(vTA);
    // cout << "Contrustor with triangles vector:\n";
    // q1.Output();
    TriangleArray s("[(0,0)(0,1)(1,0)];[(0,0)(0,3)(4,0)];[(1,1)(1,4)(1,5)]");
    cout << "Contrustor with triangles string:\n";
    s.Output();
    // TriangleArray z;
    // z.Input();
    // cout << "Output TriangleArray:\n";
    // z.Output();
    TriangleArray loadT;
    cout << "Load triangles array:\n";
    loadT.loadTriangleArray("load.txt");
    loadT.Output();
    loadT.saveTriangleArray("save.txt");

    cout << "All invalids triangles:\n";
    s.invalidTriangles();
    s.Output();

    cout << "Max Area triangle:\n";
    Triangle maxArea;
    maxArea = s.maxArea();
    maxArea.Output();

    cout << "Number of triangles types:\n";
    s.countTypeTriangles();
    return 0;
}