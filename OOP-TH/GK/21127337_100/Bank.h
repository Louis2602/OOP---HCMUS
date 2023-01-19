#pragma once
#include "HomeMortgage.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Bank
{
    string name;
    vector<HomeMortgage> list;
    int size;

public:
    void inputBankInfo();
    string getName();
    vector<HomeMortgage> getList();
    void setName(string);
    int getSize();
    void setSize(int);
    void setList(vector<HomeMortgage>);
    double totalMoney();
    void outputList();
    void countSameInterestRateVal();
    void saveInfo(string);
    void sortInfo();
};