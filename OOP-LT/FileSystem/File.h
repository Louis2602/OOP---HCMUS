//
//  File.h
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#ifndef File_h
#define File_h

#include "Data.h"

class File : public Data {
protected:
    int size;
public:
    File(string name, int size) : Data(name) {
        this->size = size;
    }
    int getSize() const;
    virtual ~File();
};

#endif /* File_h */
