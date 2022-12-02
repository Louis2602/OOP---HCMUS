#include "SplitFile.h"

int SplitFile::getSize(string source)
{
    fstream mySource(source, ios::in | ios::binary);
    mySource.seekg(0, ios::end);
    size = mySource.tellg();
    mySource.close();
    return size;
}
void SplitFile::split(string source, int n)
{
    noFiles = n;
    int sizeofEachFile = size / n;
    cout << "Size of each file: " << sizeofEachFile << endl;
    int sizeofLastFile = size - (sizeofEachFile * (n - 1));
    cout << "Size of last file: " << sizeofLastFile << endl;
    fstream readFile(source, ios::in | ios::binary);
    int countSize = 0;
    string name;
    char content;
    for (int i = 0; i < n - 1; i++)
    {
        name = to_string(i + 1) + ".txt";
        fileNames.push_back(name);
        cout << "File " << i + 1 << ": " << name << endl;
        countSize = 0;
        fstream outputFile(name, ios::out | ios::binary);
        cout << "Position start at: " << readFile.tellg() << endl;
        while (!readFile.eof() && countSize < sizeofEachFile)
        {
            readFile.read(&content, 1);
            outputFile << content;
            countSize++;
        }
        outputFile.close();
    }
    name = to_string(n) + ".txt";
    cout << "File " << n << ": " << name << endl;
    cout << "Position start at: " << readFile.tellg() << endl;
    fstream outputFile(name, ios::out | ios::binary);
    while (!readFile.eof() && countSize < sizeofLastFile)
    {
        countSize++;
        readFile >> content;
        outputFile << content;
    }
    outputFile.close();
    readFile.close();
}
void SplitFile::join(string source)
{
    fstream readFile(source, ios::in | ios::binary);
    int countSize = 0;
    string name;
    char content;
    for (int i = 0; i < noFiles - 1; i++)
    {
        name = to_string(i + 1) + ".txt";
        cout << "File " << i + 1 << ": " << name << endl;
        countSize = 0;
        fstream outputFile(name, ios::out | ios::binary);
        cout << "Position start at: " << readFile.tellg() << endl;
        while (!readFile.eof())
        {
            readFile.read(&content, 1);
            outputFile << content;
            countSize++;
        }
        outputFile.close();
    }
    readFile.close();
}