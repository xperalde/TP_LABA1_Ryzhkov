#pragma once

#include "baseClass.h"

class Keeper {
private:
    Base** array_with_element;
    int size;
    int count_element;
public:
    Keeper();
    Keeper(int size);
    Keeper(const Keeper& K);
    ~Keeper();

    void Set();
    void Change();
    void GetAll();
    void GetChoice();
    void Delete();
    Keeper& operator -=(int element);
    void loadK();
    void saveK();
};