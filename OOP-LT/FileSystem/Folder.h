//
//  Folder.h
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#ifndef Folder_h
#define Folder_h

#include <vector>
#include "Data.h"

class Folder : public Data {
protected:
    vector<Data *> data;
public:
    Folder(string name) : Data(name) {}
    int getSize() const;
    void addData(Data *d);
    void display(int indent) const;
    virtual ~Folder();
};

#endif /* Folder_h */
