#include "mystring.h"

int MyString::getLength()
{
    return length;
}

void MyString::setLength(int _len)
{
    this->length = _len;
}
void MyString::setStr(char *_str)
{
    this->str = new char[length];
    for (int i = 0; i < length; i++)
        str[i] = _str[i];
}
char *MyString::getStr()
{
    char *tmp = str;
    return tmp;
}

char *MyString::subString(int start, int len)
{
    int n = min(length, start + len);
    char *sub = new char[n - start];
    for (int i = start; i < n; i++)
        sub[i - start] = str[i];
    sub[n - start] = '\0';
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
char *MyString::replace(int start, int len, char *str)
{
    int strlen = 0, newLength, strIndex = 0;
    while (str[strlen])
        strlen++;
    newLength = this->getLength() - len + strlen;
    char *ans = new char[newLength];
    char *p1, *p2, *p3;
    p1 = subString(0, start);
    p3 = subString(start + len, this->getLength() - (start + len - 1));
    for (int i = 0; i < start; i++)
    {
        ans[strIndex] = p1[i];
        strIndex++;
    }
    for (int i = 0; i < strlen; i++)
    {
        ans[strIndex] = str[i];
        strIndex++;
    }
    for (int i = 0; i < this->getLength() - (start + len - 1); i++)
    {
        ans[strIndex] = p3[i];
        strIndex++;
    }
    return ans;
}
char *MyString::insert(int pos, char *str)
{
    int sublen = 0;
    while (str[sublen] != '\0')
        sublen++;

    int n = this->getLength() + sublen + 1;
    char *newStr = new char[n];
    for (int i = 0; i < pos; i++)
        newStr[i] = this->getStr()[i];
    for (int i = pos; i <= sublen; i++)
        newStr[i] = str[i - pos];
    for (int i = sublen + 1; i < this->getLength(); i++)
        newStr[i] = this->getStr()[i];
    newStr[n] = '\0';
    return newStr;
}

char *MyString::erase(int start, int len)
{
    if (len + start > this->getLength())
    {
        int n = start;

        char *sub = new char[n];

        int i{};
        for (i; i < n; i++)
        {
            sub[i] = str[i];
        }
        setLength(n);
        setStr(sub);
        sub[n] = '\0';
        return sub;
    }
    else
    {
        int n = this->getLength() - len;

        char *sub = new char[n];

        int i{};
        for (i; i < start; i++)
            sub[i] = str[i];

        // i = start

        for (i; i < n; i++)
            sub[i] = str[i + len];
        setLength(n);
        setStr(sub);
        sub[n] = '\0';
        return sub;
    }
}

int MyString::find(MyString f)
{
    int index = 0;
    int ans = 0;
    char *temp = f.getStr();
    if (f.getLength() > this->length)
        return -1;
    while (index < this->length && (index + f.getLength() <= this->length))
    {
        if (this->str[index] == temp[0])
        {
            for (int i = 0; i < sizeof(f); i++)
            {
                if (this->str[i + index] != temp[i])
                {
                    break;
                }
            }
            return index;
        }
        index++;
    }
    return -1;
}

istream &operator>>(istream &in, MyString &s)
{
    char *temp = new char[256];
    int count = 0;
    in.getline(temp, 256);
    while (temp[count] != '\0')
        count++;
    temp[count] = '\0';
    s.setLength(count);
    s.setStr(temp);
    delete[] temp;
    return in;
}
ostream &operator<<(ostream &out, MyString &s)
{
    char *tmp = s.getStr();
    for (int i = 0; i < s.getLength(); i++)
        out << tmp[i];
    cout << endl;
    return out;
}