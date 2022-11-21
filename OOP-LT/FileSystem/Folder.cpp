//
//  Folder.cpp
//  FileSystem
//
//  Created by Kha Do on 11/18/22.
//

#include "Folder.h"

int Folder::getSize() const {
    int sum = 0;
    for (int i = 0; i < this->data.size(); i++) {
        sum += this->data[i]->getSize();
    }
    return sum;
}

void Folder::addData(Data *d) {
    this->data.push_back(d);
}

void Folder::display(int indent) const {
    Data::display(indent);
    for (int i = 0; i < this->data.size(); i++) {
        this->data[i]->display(indent + 1);
    }
}

Folder::~Folder() {
    for (int i = 0; i < this->data.size(); i++) {
        delete this->data[i];
    }
}
