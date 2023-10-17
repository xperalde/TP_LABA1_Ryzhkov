#include "Keeper.h"
#include "baseClass.h"

void Keeper:: add(Base* obj) {
    objects.push_back(obj);
}

void Keeper::remove(Base* obj) {
    auto it = std::find(objects.begin(), objects.end(), obj);
    if (it != objects.end()) {
        delete* it;
        objects.erase(it);
    }
}

void Keeper:: clear() {
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
}

void Keeper::save(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        for (auto obj : objects) {
            file.write(reinterpret_cast<const char*>(obj), sizeof(Base));
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

void Keeper:: load(const std::string& filename) {
    clear();

    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        int size = file.tellg() / sizeof(Base);
        file.seekg(0, std::ios::beg);

        for (int i = 0; i < size; i++) {
            Base* obj = new Base();
            file.read(reinterpret_cast<char*>(obj), sizeof(Base));
            objects.push_back(obj);
        }

        file.close();
    }
    else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}