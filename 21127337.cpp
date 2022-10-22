#include <iostream>
#include <sstream>
using namespace std;

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
char Add(char a, char b)
{
    if (b == 0)
        return a;
    return Add(a ^ b, (unsigned)(a & b) << 1);
}
char Subtract(char a, char b)
{
    b = ~b + 1;
    return Add(a, b);
}
char Multiply(char Q, char M)
{
    // using Booth's Multiplication algorithm
    char A = 0, QNegative1 = 0;
    int k = 8;
    char twoLastBit;
    while (k > 0)
    {
        // last bit of Q
        char Q0 = Q & 1;
        twoLastBit = Q0 << 1 | QNegative1;
        if (twoLastBit == 2)
        {
            A = Subtract(A, M);
        }
        else if (twoLastBit == 1)
        {
            A = Add(A, M);
        }
        QNegative1 = Q & 1, Q >>= 1;
        Q ^= (-(A & 1) ^ Q) & (1UL << 7);
        A >>= 1;
        k--;
    }
    char ans = A << 8 | Q;
    return ans;
}
char Divide(char Q, char M, int mode)
{
    char A = 0;
    int k = 8;
    bool checkNegative = false;
    if (M == 0)
        return '\0';
    if (Q < 0)
    {
        Q *= -1;
        checkNegative = true;
    }
    if (M < 0)
    {
        M *= -1;
        checkNegative = true;
    }
    if (M && Q)
        checkNegative = false;
    while (k > 0)
    {
        A <<= 1;
        A ^= (-((Q >> 7) & 1) ^ A) & (1UL);
        Q <<= 1;
        A = Subtract(A, M);
        if (A < 0)
        {
            Q ^= (-0 ^ Q) & (1UL);
            A = Add(A, M);
        }
        else
            Q ^= (-1 ^ Q) & (1UL);
        k--;
    }
    char ans;
    if (mode)
        checkNegative ? ans = Q *-1 : ans = Q;
    else
        ans = A;
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

    char ans, arrAns[8];

    ans = Add(a, b);
    Dec2Bin(ans, arrAns);
    cout << "A + B (Binary): ";
    output(arrAns);
    cout << "A + B (Decimal): " << (int)ans << '\n';

    ans = Subtract(a, b);
    Dec2Bin(ans, arrAns);
    cout << "A - B (Binary): ";
    output(arrAns);
    cout << "A - B (Decimal): " << (int)ans << '\n';

    ans = Multiply(a, b);
    Dec2Bin(ans, arrAns);
    cout << "A * B (Binary): ";
    output(arrAns);
    cout << "A * B (Decimal): " << (int)ans << '\n';

    ans = Divide(a, b, 1);
    Dec2Bin(ans, arrAns);
    cout << "A / B (Binary): ";
    output(arrAns);
    cout << "A / B (Decimal): " << (int)ans << '\n';
    ans = Divide(a, b, 0);
    Dec2Bin(ans, arrAns);
    cout << "A % B (Binary): ";
    output(arrAns);
    cout << "A % B (Decimal): " << (int)ans << '\n';
    return 0;
}
