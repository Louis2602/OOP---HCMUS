#include "Array.h"
using namespace std;

int main()
{
    cout << "Array constructor from int[] with given size: \n";
    int ar[] = {1, 2, 3, 4, 5};
    Array a(ar, 5);
    cout << a;

    cout << "Without constructor: \n";
    Array b;
    cin >> b;
    cout << b;

    cout << "Array constructor with given size: \n";
    Array c(5);
    cin >> c;
    cout << c;

    cout << "Array constructor from another array object: \n";
    Array t(a);
    cout << t;

    cout << "Operator =: \n";
    Array d;
    d = b;
    cout << d;

    cout << "Type casting: \n";
    int *arr;
    cout << arr;

    return 0;
}