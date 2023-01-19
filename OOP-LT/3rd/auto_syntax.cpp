#include <iostream>
using namespace std;

int main()
{
    int a[5] = {3, 2, 4, 5, 1};
    for (auto &x : a)
        cout << x << " ";
    // declare a function within a function
    auto print = [&]()
    {
        cout << "\nHello world\n";
        for (auto &x : a)
            cout << x << " ";
    };
    print();
    return 0;
}