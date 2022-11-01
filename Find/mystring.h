#pragma once
#pragma once
#include <iostream>

using namespace std;

class MyString
{
private:
    char *str;
    int length;

public:
    int getLength()
    {
        return length;
    }
    void setLength(int _len)
    {
        this->length = _len;
    }
    void setStr(char *_str)
    {
        this->str = new char[length];
        for (int i = 0; i < length; i++)
            str[i] = _str[i];
    }
    char *getStr()
    {
        return str;
    }
    char *subString(int, int);
    char *operator+(const MyString &);
    char *insert(int, char *);
    char *erase(int, int);
    int find(char *);
};