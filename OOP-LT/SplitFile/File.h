#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class File
{
private:
    int size;
    int noFiles;
    vector<string> fileNames;

public:
    int getSize(string);
    void split();
    void join();
};