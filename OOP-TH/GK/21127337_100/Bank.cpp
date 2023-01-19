#include "Bank.h"

void Bank::inputBankInfo()
{
    string _name;
    cout << "Input bank's name: ";
    cin >> _name;
    setName(_name);
    int n;
    cout << "Enter number of home mortgages: ";
    cin >> n;
    double loan, rate;
    int years;
    string name;
    vector<HomeMortgage> listHm;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Input loan, rate, years " << i + 1 << ": ";
        cin >> loan >> rate >> years;
        HomeMortgage hm;
        hm.setName(name);
        hm.setLoan(loan);
        hm.setRate(rate);
        hm.setYears(years);
        listHm.push_back(hm);
    }
    setSize(n);
    setList(listHm);
}
int Bank::getSize()
{
    return size;
}
void Bank::setSize(int _size)
{
    size = _size;
}
void Bank::outputList()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Customer's name: " << list[i].getName() << endl;
        cout << list[i].getLoan() << ", " << list[i].getRate() << ", " << list[i].getYears() << endl;
    }
}
void Bank::setName(string _name)
{
    name = _name;
}
string Bank::getName()
{
    return name;
}
void Bank::setList(vector<HomeMortgage> l)
{
    list = l;
}
vector<HomeMortgage> Bank::getList()
{
    return list;
}
double Bank::totalMoney()
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += list[i].calcMonthlyPayment();
    return sum;
}
void Bank::countSameInterestRateVal()
{
    double rate;
    cout << "Enter interest rate value: ";
    cin >> rate;
    int cnt = 0;
    for (int i = 0; i < size; i++)
        if (list[i].getRate() == rate / 100)
            cnt++;
    cout << "Number of customers are applied that interest rate value: " << cnt << endl;
}
bool compareName(HomeMortgage i1, HomeMortgage i2)
{
    return (i1.getName() < i2.getName());
}
bool compareLoanAmount(HomeMortgage i1, HomeMortgage i2)
{
    return (i1.getLoan() > i2.getLoan());
}
void Bank::sortInfo()
{
    sort(list.begin(), list.end(), compareLoanAmount);
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((list[i].getLoan() == list[j].getLoan()) && (list[i].getName() > list[j].getName()))
                swap(list[i], list[j]);
}
void Bank::saveInfo(string filename)
{
    fstream fs(filename, ios::out);
    fs << "Bank's name: " << name << endl;
    fs << "Number of HomeMortgage: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        fs << "Customer " << i + 1 << "_" << list[i].getName() << ": " << list[i].getLoan() << ", " << list[i].getRate() << ", " << list[i].getYears() << endl;
    }
    fs.close();
}