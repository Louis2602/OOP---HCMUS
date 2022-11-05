#include "IntArray.h"

void IntArray::setArr(int *_arr)
{
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = _arr[i];
}
int *IntArray::getArr()
{
    return arr;
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
        cout << "_arr[" << i << "]: ";
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
ostream &operator<<(ostream &out, IntArray &IntArr)
{
    int *arr = IntArr.getArr();
    int n = IntArr.getSize();
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    cout << '\n';
    return out;
}
IntArray &IntArray::operator=(IntArray a)
{
    this->setArr(a.getArr());
    if (this != &a)
    {
        delete[] arr;
        size = a.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = a.arr[i];
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