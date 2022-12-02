#include "SplitFile.h"

int SplitFile::getSize(string source)
{
    fstream mySource(source, ios::in | ios::binary);
    mySource.seekg(0, ios::end);
    size = mySource.tellg();
    mySource.close();
    return size;
}
void SplitFile::split()
{
    int sizeofEachFile;
    string source;
    cout << "Enter the size (S): ";
    cin >> sizeofEachFile;
    cout << "Enter a filename (N): ";
    cin >> source;
    size = this->getSize(source);
    cout << "Your file's size is: " << size << endl;
    cout << "Enter number of piece: ";
    cin >> noFiles;
    int sizeofLastFile = size - (sizeofEachFile * (noFiles - 1));
    fstream readFile(source, ios::in | ios::binary);
    int countSize = 0;
    string name;
    char content;
    cout << "============SPLITTER============\n";
    for (int i = 0; i < noFiles - 1; i++)
    {
        if (noFiles < 10)
        {
            name = source + ".00" + to_string(i + 1);
            cout << "F.00" << i + 1 << " => " << name << endl;
        }
        else if (noFiles >= 10 && noFiles < 100)
        {
            name = source + ".0" + to_string(i + 1);
            cout << "F.0" << i + 1 << " => " << name << endl;
        }
        else
        {
            name = source + "." + to_string(i + 1);
            cout << "F." << i + 1 << " => " << name << endl;
        }
        fileNames.push_back(name);
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
    if (noFiles < 10)
    {
        name = source + ".00" + to_string(noFiles);
        cout << "F.00" << noFiles << " => " << name << endl;
    }
    else if (noFiles >= 10 && noFiles < 100)
    {
        name = source + ".0" + to_string(noFiles);
        cout << "F.0" << noFiles << " => " << name << endl;
    }
    else
    {
        name = source + "." + to_string(noFiles);
        cout << "F." << noFiles << " => " << name << endl;
    }
    fileNames.push_back(name);
    cout << "Position start at: " << readFile.tellg() << endl;
    fstream outputFile(name, ios::out | ios::binary);
    countSize = 0;
    while (!readFile.eof() && countSize < sizeofLastFile)
    {
        countSize++;
        readFile.read(&content, 1);
        outputFile << content;
    }
    cout << "Your file has been splited into " << noFiles << " successfully." << endl;
    outputFile.close();
    readFile.close();
}
void SplitFile::join()
{
    string source;
    cout << "Enter the first piece name (N): ";
    cin >> source;
    // stringstream ss(source);
    // string tmp;
    // getline(ss, tmp, '.');
    // getline(ss, tmp);
    stringstream ss(fileNames[0]);
    string fileName, fileExtension;
    getline(ss, fileName, '.');
    getline(ss, fileExtension, '.');
    string name = fileName + "_AfterJoined." + fileExtension;
    fstream readFile(name, ios::out | ios::binary);
    char content;
    cout << "============JOINER============\n";
    for (int i = 0; i < noFiles; i++)
    {
        fstream inputFile(fileNames[i], ios::in | ios::binary);
        readFile << inputFile.rdbuf();
        inputFile.close();
    }
    cout << "Your file has been joined from " << noFiles << " successfully." << endl;
    readFile.close();
}