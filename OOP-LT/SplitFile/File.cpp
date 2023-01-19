#include "File.h"
#include <direct.h>

int File::getSize(string source)
{
    fstream mySource(source, ios::in | ios::binary);
    mySource.seekg(0, ios::end);
    size = mySource.tellg();
    mySource.close();
    return size;
}
void File::split()
{
    int sizeofEachFile;
    string source;
    do
    {
        cout << "Enter a filename (N): ";
        cin >> source;
        size = getSize(source);
        if (size == -1)
            cout << "[ERROR]: Cannot find file " << source << endl;
    } while (size == -1);
    cout << "Your file's size is: " << size << " bytes" << endl;
    cout << "Enter the size of a piece (S): ";
    cin >> sizeofEachFile;
    noFiles = size / sizeofEachFile + 1;
    int sizeofLastFile = size - (sizeofEachFile * (noFiles - 1));
    fstream readFile(source, ios::in | ios::binary);
    int countSize = 0;
    string name;
    char content;
    cout << "============SPLITTER============\n";
    for (int i = 0; i < noFiles - 1; i++)
    {
        if (i < 10)
        {
            name = source + ".00" + to_string(i + 1);
            cout << "F.00" << i + 1 << " => " << name << endl;
        }
        else if (i >= 10 && i < 100)
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
        cout << "Position start at: " << readFile.tellg() << ", size: " << sizeofEachFile << endl;
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
    cout << "Position start at: " << readFile.tellg() << ", size: " << sizeofLastFile << endl;
    fstream outputFile(name, ios::out | ios::binary);
    countSize = 0;
    while (!readFile.eof() && countSize < sizeofLastFile)
    {
        countSize++;
        readFile.read(&content, 1);
        outputFile << content;
    }
    cout << "Your file has been splited into " << noFiles << " subfiles successfully." << endl;
    outputFile.close();
    readFile.close();
}
void File::join()
{
    string source;
    do
    {
        cout << "Enter the first piece name (N): ";
        cin >> source;
        if (source != fileNames[0])
            cout << "[ERROR]: You not entered the first piece name (F.001) so the file could not be merged correctly!!\n";
    } while (source != fileNames[0]);
    stringstream ss(source);
    string fileName, fileExtension;
    getline(ss, fileName, '.');
    getline(ss, fileExtension, '.');
    if (mkdir("./output") == -1)
        cerr << " Error : " << strerror(errno) << endl;
    string name = "./output/" + fileName + "." + fileExtension;
    fstream readFile(name, ios::out | ios::binary);
    char content;
    cout << "============JOINER============\n";
    for (int i = 0; i < noFiles; i++)
    {
        fstream inputFile(fileNames[i], ios::in | ios::binary);
        readFile << inputFile.rdbuf();
        cout << "Merged file " << fileNames[i] << " done!!" << endl;
        inputFile.close();
    }
    cout << "Your file has been joined from " << noFiles << " subfiles successfully." << endl;
    cout << "File output: " << name << endl;
    readFile.close();
}