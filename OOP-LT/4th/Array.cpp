#include "Array.h"

Array::Array()
{
    size = 0;
    arr = new int[size];
}
Array::Array(int n)
{
    setSize(n);
}
Array::Array(int _arr[], int n)
{
    setArr(_arr);
    setSize(n);
}
Array::Array(const Array &_arr)
{
    int _size = _arr.size;
    int *pArr = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        pArr[i] = _arr.arr[i];
        cout << pArr[i] << " ";
    }
}
Array::~Array()
{
    delete[] arr;
}
int *Array::getArr()
{
    int *_arr = arr;
    return _arr;
}
void Array::setArr(int *_arr)
{
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = _arr[i];
}
int Array::getSize()
{
    int _size = size;
    return _size;
}
void Array::setSize(int _size)
{
    size = _size;
}
istream &operator>>(istream &in, Array &Arr)
{
    int n;
    if (Arr.getSize() == 0)
    {
        cout << "Input size of array: ";
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
    Arr.setSize(n);
    Arr.setArr(A);
    return in;
}
ostream &operator<<(ostream &out, Array &Arr)
{
    int *arr = Arr.getArr();
    int n = Arr.getSize();
    cout << "Output: ";
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    cout << '\n';
    return out;
}
Array &Array::operator=(Array a)
{
    this->setSize(a.getSize());
    this->setArr(a.getArr());
    return *this;
}
Array::operator int *() const
{
    return arr;
}
int &Array::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return arr[index];
}