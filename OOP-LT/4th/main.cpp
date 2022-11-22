#include "MyIntArray.h"
using namespace std;

int main()
{
    cout << "Array constructor from int[] with given size: \n";
    int ar[] = {1, 2, 3, 4, 5};
    MyIntArray a(ar, 5);
    cout << a;
    cout << "------------------------------------" << endl;
    cout << "Default constructor: \n";
    MyIntArray b;
    cin >> b;
    cout << b;
    cout << "------------------------------------" << endl;
    cout << "Array constructor with given size: \n";
    MyIntArray c(5);
    cin >> c;
    cout << c;
    cout << "------------------------------------" << endl;
    cout << "Array constructor from another array object: \n";
    MyIntArray t(b);
    cout << t;
    cout << "------------------------------------" << endl;
    cout << "Operator =: \n";
    MyIntArray d;
    d = t;
    cout << d;
    cout << "------------------------------------" << endl;
    cout << "Type casting: \n";
    int *tmp = (int *)(a);
    for (int i = 0; i < a.getSize(); i++)
        cout << tmp[i] << " ";

    return 0;
}