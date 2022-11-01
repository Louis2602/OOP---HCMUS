#include "mystring.h"

char *MyString::subString(int start, int len)
{
    // int n = min(length, start+len);
    // char *sub = new char[n - start];
    char *sub = new char[len];
    for (int i = start; i < start + len; i++)
        sub[i - start] = str[i];
    return sub;
}

char *MyString::operator+(const MyString &b)
{
    char *c = new char[length + b.length + 1];
    for (int i = 0; i < length; i++)
        c[i] = str[i];
    for (int i = length; i < length + b.length; i++)
        c[i] = b.str[i - length];
    c[length + b.length] = '\0';
    return c;
}

char *MyString::insert(int pos, char *str)
{
    int sublen = 0;
    while (str[sublen] != '\0')
        sublen++;

    char *newStr = new char[length + sublen + 1];
    for (int i = 0; i < pos; i++)
        newStr[i] = this->str[i];
    for (int i = 0; i < sublen - 1; i++)
        newStr[pos + i] = str[i];
    for (int i = pos; i < length; i++)
        newStr[sublen + i] = this->str[i];
    newStr[length + sublen] = '\0';
    this->str = new char[length + sublen + 1];
    for (int i = 0; i < length + sublen; i++)
        this->str[i] = newStr[i];
    this->str[length + sublen] = '\0';
    this->length = length + sublen;
    return newStr;
}

char *MyString::erase(int start, int len)
{
    if (len + start > this->length)
    {
        int n = start;

        char *sub = new char[n];

        int i{};
        for (i; i < n; i++)
        {
            sub[i] = str[i];
        }
        setLength(n);
        // setStr(sub, n);
        return sub;
    }
    else
    {
        int n = this->length - len;

        char *sub = new char[n];

        int i{};
        for (i; i < start; i++)
        {
            sub[i] = str[i];
        }

        // i = start

        for (i; i < n; i++)
        {
            sub[i] = str[i + len];
        }
        setLength(n);
        // setStr(sub, n);
        return sub;
    }
}

int MyString::find(char *f)
{
    int index = 0;
    if (sizeof(f) > this->length)
        return -1;
    while (index < this->length && index + sizeof(f) <= this->length)
    {
        if (this->str[index] == f[0])
        {
            for (int i = 0; i < sizeof(f); i++)
            {
                if (this->str[i + index] != f[i])
                {
                    return -1;
                }
            }
        }
    }
    return index;
}