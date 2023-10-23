#pragma once
#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;


class Base
{
public:
    Base();
    Base(int size);
    Base(const Base& B);
    ~Base();
    virtual void Set() = 0; 
    virtual void Get() = 0; 
    virtual void Delete() = 0; 
    virtual void Change() = 0;
    virtual void Load(int count, string line) = 0;
    virtual string Save(int count) = 0;
    virtual int TypeID() = 0; 
};

class Auto :public Base
{
private:
    string marka;
    string model;
    string obem_dvigatelya;
    string cvet;
    string tipKPP;

public:
    Auto();
    Auto(string marka, string model, string obem_dvigatelya, string cvet, string tipKPP);
    Auto(const Auto& B);
    ~Auto();

    void Set() override; 
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

class Moto :public Base
{
private:
    string marka;
    string model;
    string obem_dvigatelya;
    string moshnost;
    string tip_mestnosti;

public:
    Moto();
    Moto(string marka, string model, string obem_dvigatelya, string moshnost, string tip_mestnosti);
    Moto(const Moto& S); 
    ~Moto();

   
    void Set() override;
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

class Bus :public Base
{
private:
    string marka;
    string model;
    string kolvo_sidiachih_mest;
    string obshee_kolvo_mest;
    string konechnii_punkt;

public:
    Bus(); 
    Bus(string marka, string model, string kolvo_sidiachih_mest, string obshee_kolvo_mest, string konechnii_punkt);
    Bus(const Bus& C);
    ~Bus();

    void Set() override;
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};
#endif