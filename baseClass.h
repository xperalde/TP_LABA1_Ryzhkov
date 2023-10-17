#pragma once

class Base {
public:
    virtual ~Base() {}
    virtual void print() = 0;
    virtual void modify() = 0;
    //virtual set
    //virtual get
};