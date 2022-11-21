//
//  main.cpp
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#include <iostream>
#include "Data.h"
#include "File.h"
#include "Folder.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Folder *root = new Folder("root");
    File *f1 = new File("hello.exe", 100);
    File *f2 = new File("content.txt", 10);
    Folder *subFolder = new Folder("Documents");
    Folder *subFolder2 = new Folder("Windows");
    Folder *subFolder3 = new Folder("System32");
    Folder *subFolder4 = new Folder("bin");
    subFolder2->addData(subFolder3);
    subFolder3->addData(subFolder4);
    subFolder->addData(f2);
    root->addData(f1);
    root->addData(subFolder);
    root->addData(subFolder2);
    root->display(0);
    cout << "Total size: " << root->getSize() << endl;
    delete root;
    return 0;
}
