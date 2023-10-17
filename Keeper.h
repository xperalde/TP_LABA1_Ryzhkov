#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class Keeper {
private:
    Keeper();
    ~Keeper();
    std::vector<Base*> objects;
public:
    Keeper() {}
    ~Keeper() {
        clear();
    }
    void add(Base* obj);
    void remove(Base* obj);
    void clear();
    void save(const std::string& filename);
    void load(const std::string& filename);
};