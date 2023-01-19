#include "MyIntArray.h"

MyIntArray::MyIntArray()
{
    size = 0;
    arr = nullptr;
}
MyIntArray::MyIntArray(int n)
{
    setContent(arr, n);
}
MyIntArray::MyIntArray(int _arr[], int n)
{
    setContent(_arr, n);
}
MyIntArray::MyIntArray(const MyIntArray &_arr)
{
    int _size = _arr.size;
    int *pArr = new int[_size];
    for (int i = 0; i < _size; i++)
        pArr[i] = _arr.arr[i];
    setContent(pArr, _size);
}
MyIntArray::~MyIntArray()
{
    if (size > 0)
    {
        size = 0;
        delete[] arr;
        arr = nullptr;
    }
}
int *MyIntArray::getArr()
{
    int *_arr = new int[size];
    for (int i = 0; i < size; i++)
        _arr[i] = arr[i];
    return _arr;
}
void MyIntArray::setContent(int *_arr, int _size)
{
    size = _size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = _arr[i];
}
int MyIntArray::getSize()
{
    return size;
}

istream &operator>>(istream &in, MyIntArray &Arr)
{
    int n;
    if (Arr.getSize() == 0)
    {
        cout << "Input size of MyIntArray: ";
        cin >> n;
    }
    else
        n = Arr.getSize();
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    Arr.setContent(A, n);
    delete[] A;
    return in;
}
ostream &operator<<(ostream &out, const MyIntArray &Arr)
{
    int *arr = Arr.arr;
    int n = Arr.size;
    cout << "Output: ";
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    cout << '\n';
    return out;
}
MyIntArray &MyIntArray::operator=(const MyIntArray &src)
{
    if (this != &src)
    {
        delete[] arr;
        size = src.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = src.arr[i];
    }
    return *this;
}
MyIntArray::operator int *() const
{
    int *tmp = new int[size];
    for (int i = 0; i < size; i++)
        tmp[i] = arr[i];
    return tmp;
}
int &MyIntArray::operator[](int index)
{
    if (index >= size)
    {
        cout << "MyIntArray index out of bound, exiting";
        exit(0);
    }
    return arr[index];
}
