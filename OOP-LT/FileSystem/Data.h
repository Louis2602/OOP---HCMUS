//
//  Data.h
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#ifndef Data_h
#define Data_h

#include <string>
#include <iostream>

using namespace std;

class Data {
protected:
    string name;
public:
    Data(string name);
    string getName() const;
    virtual int getSize() const = 0;
    virtual void display(int indent) const;
    virtual ~Data();
};

#endif /* Data_h */
