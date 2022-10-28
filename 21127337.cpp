#include <iostream>
#include <cstring>

using namespace std;

char *Complement(char *b)
{
    char *comp = new char[8];
    memset(comp, 0, 8);
    int cnt = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (cnt >= 1)
            comp[i] = !b[i];
        if (b[i] == 1)
        {
            cnt++;
            if (cnt == 1)
                comp[i] = b[i];
        }
    }
    return comp;
}
void shiftRight1(char *a)
{
    for (int i = 7; i >= 1; i--)
        a[i] = a[i - 1];
}
void shiftLeft1(char *a)
{
    for (int i = 0; i < 7; i++)
        a[i] = a[i + 1];
    a[7] = 0;
}
void copy(char *a, char *b)
{
    for (int i = 0; i < 8; i++)
        a[i] = b[i];
}
char *concat(char *a, char *b)
{
    char *new_str = new char[8];
    for (int i = 0; i < 8; i++)
        new_str[i] = a[i];
    for (int i = 9; i < 16; i++)
        new_str[i] = b[i];
    return new_str;
}
void input(int &a, int &b)
{
    cout << "Input A (Decimal): ";
    cin >> a;
    cout << "Input B (Decimal): ";
    cin >> b;
}
void output(char arr[8])
{
    for (int i = 0; i < 8; i++)
        cout << (int)arr[i];
    cout << '\n';
}
void Dec2Bin(char n, char arr[8])
{
    for (int i = 7; i >= 0; i--)
    {
        char k = n >> i;
        k & 1 ? arr[7 - i] = 1 : arr[7 - i] = 0;
    }
}
int Bin2Dec(char *arr)
{
    int dec_value = 0;
    int base = 1;
    for (int i = 7; i >= 0; i--)
    {
        if (arr[i] == 1)
            dec_value += base;
        base = base * 2;
    }
    if (arr[0] == 1)
        return dec_value - 256;
    return dec_value;
}
char *Add(char a[8], char b[8])
{
    char *ans = new char[8];
    char carry = 0;
    for (int i = 7; i >= 0; i--)
    {
        char sum = (a[i] ^ b[i] ^ carry);
        ans[i] = sum;
        carry = (a[i] & b[i]) | (b[i] & carry) | (a[i] & carry);
    }
    return ans;
}
char *Subtract(char a[8], char b[8])
{
    char *ans = new char[8];
    // 2's complement for b
    char *comp;
    comp = Complement(b);
    ans = Add(a, comp);
    return ans;
}
char *Multiply(char a[8], char b[8])
{
    // using Booth's Multiplication algorithm
    char *Q = new char[8];
    char *M = new char[8];
    copy(Q, a);
    copy(M, b);
    char *ans, *A = new char[8];
    memset(A, 0, 8);
    char QNegative1 = 0, twoLastBit;
    int k = 8;
    while (k > 0)
    {
        // last bit of Q
        char Q0 = Q[7];
        twoLastBit = Q0 << 1 | QNegative1;
        if (twoLastBit == 2)
            A = Subtract(A, M);
        else if (twoLastBit == 1)
            A = Add(A, M);

        char lastBitOfA = A[7];
        shiftRight1(A);
        QNegative1 = Q[7];
        shiftRight1(Q);
        Q[0] = lastBitOfA;
        k--;
    }
    ans = Q;
    return ans;
}
bool isZero(char *a)
{
    for (int i = 0; i < 8; i++)
        if (a[i] != 0)
            return 0;
    return 1;
}
char *Divide(char a[8], char b[8], int mode)
{
    // char *Q, *M = new char[8];
    char *Q = new char[8];
    char *M = new char[8];
    char *comp;
    copy(Q, a);
    copy(M, b);
    char *ans, *A = new char[8];
    memset(A, 0, 8);
    int k = 8;
    bool checkNegative = false;
    bool checkSoChia = false;
    if (isZero(M))
        return ans;
    if ((M[0] == 0 && Q[0] == 0) || (M[0] == 1 && Q[0] == 1))
        checkNegative = false;
    else if (Q[0] == 1 && M[0] == 0)
    {
        comp = Complement(Q);
        copy(Q, comp);
        checkNegative = true;
        checkSoChia = false;
    }
    else if (Q[0] == 0 && M[0] == 1)
    {
        comp = Complement(M);
        copy(M, comp);
        checkNegative = true;
        checkSoChia = true;
    }
    while (k > 0)
    {
        shiftLeft1(A);
        A[7] = Q[0];
        shiftLeft1(Q);
        A = Subtract(A, M);
        if (A[0] == 1)
        {
            Q[7] = 0;
            A = Add(A, M);
        }
        else
            Q[7] = 1;
        k--;
    }
    char *compQ, *compA;
    compQ = Complement(Q);
    compA = Complement(A);
    if (mode)
    {
        if (checkNegative)
            ans = compQ;
        else
            return Q;
    }
    else
    {
        if (checkNegative)
        {
            if (checkSoChia)
                ans = A;
            else
                ans = compA;
        }
        else
            ans = A;
    }
    return ans;
}
int main()
{
    int aDec, bDec;
    char a, b;
    char arrA[8], arrB[8];

    input(aDec, bDec);
    a = (char)aDec, b = (char)bDec;

    Dec2Bin(a, arrA);
    Dec2Bin(b, arrB);
    cout << "A (Binary): ";
    output(arrA);
    cout << "B (Binary): ";
    output(arrB);

    char *arrAns;
    cout << "A + B (Binary): ";
    arrAns = Add(arrA, arrB);
    output(arrAns);
    cout << "A + B (Decimal): " << Bin2Dec(arrAns) << '\n';

    cout << "A - B (Binary): ";
    arrAns = Subtract(arrA, arrB);
    output(arrAns);
    cout << "A - B (Decimal): " << Bin2Dec(arrAns) << '\n';

    cout << "A * B (Binary): ";
    arrAns = Multiply(arrA, arrB);
    output(arrAns);
    cout << "A * B (Decimal): " << Bin2Dec(arrAns) << '\n';

    cout << "A / B (Binary): ";
    arrAns = Divide(arrA, arrB, 1);
    output(arrAns);
    cout << "A / B (Decimal): " << Bin2Dec(arrAns) << '\n';

    cout << "A % B (Binary): ";
    arrAns = Divide(arrA, arrB, 0);
    output(arrAns);
    cout << "A % B (Decimal): " << Bin2Dec(arrAns) << '\n';

    return 0;
}
