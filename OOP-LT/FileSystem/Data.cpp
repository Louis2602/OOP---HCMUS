//
//  Data.cpp
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#include "Data.h"

Data::Data(string name) {
    this->name = name;
}

string Data::getName() const {
    return this->name;
}

void Data::display(int indent) const {
    for (int i = 0; i < indent; i++) {
        cout << "  ";
    }
    cout << this->name << endl;
}

Data::~Data() {
    
}
