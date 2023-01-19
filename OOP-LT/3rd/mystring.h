#pragma once
#include <iostream>

using namespace std;

class MyString
{
private:
    char *str;
    int length;

public:
    int getLength();
    void setLength(int);
    void setStr(char *);
    char *getStr();
    char *subString(int, int);
    char *operator+(const MyString &);
    char *insert(int, char *);
    char *erase(int, int);
    char *replace(int, int, char *);
    int find(MyString);
    friend ostream &operator<<(ostream &, MyString &);
    friend istream &operator>>(istream &, MyString &);
};