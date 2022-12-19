#include "IntArray.h"

int *IntArray::getArr()
{
    return arr;
}
void IntArray::setArr(int *_arr)
{
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = _arr[i];
}
int IntArray::getSize()
{
    return size;
}
void IntArray::setSize(int _size)
{
    size = _size;
}
void IntArray::Input()
{
    int n;
    cout << "Input size of array: ";
    cin >> n;
    int *_arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]: ";
        cin >> _arr[i];
    }
    this->setSize(n);
    this->setArr(_arr);
}
istream &operator>>(istream &in, IntArray &IntArr)
{
    int n;
    cout << "Input size of array: ";
    cin >> n;
    int *_arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "_arr[" << i << "]: ";
        cin >> _arr[i];
    }
    IntArr.setSize(n);
    IntArr.setArr(_arr);
    return in;
}
ostream &operator<<(ostream &out, const IntArray &IntArr)
{
    for (int i = 0; i < IntArr.size; i++)
        out << IntArr.arr[i] << " ";
    cout << '\n';
    return out;
}
IntArray &IntArray::operator=(const IntArray &src)
{
    if (this != &src)
    {
        // Base::operator=(src) if inheritance
        delete[] arr;
        size = src.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = src.arr[i];
    }
    return *this;
}
IntArray::operator int() const
{
    return size;
}
int &IntArray::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return arr[index];
}
