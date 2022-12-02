#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class SplitFile
{
private:
    int size;
    int noFiles;
    vector<string> fileNames;

public:
    int getSize(string);
    void split(string, int);
    void join(string);
};