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
    if ((M && Q) || (!M && !Q))
        checkNegative = false;
    if (Q < 0 && M > 0)
    {
        Q *= -1;
        checkNegative = true;
    }
    if (M < 0 && Q > 0)
    {
        M *= -1;
        checkNegative = true;
    }
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
        checkNegative ? ans = A *-1 : ans = A;
    return ans;
}