#include <iostream>
#include "baseClass.h"

using namespace std;

Base::Base()
{
    cout << "Вызван конструктор класса Base" << endl;
}
Base::Base(int size)
{
    cout << "Вызван конструктор с параметром класса Base" << endl;
}
Base::Base(const Base& B)
{
    cout << "Вызван конструктор копирования класса Base" << endl;
}
Base::~Base()
{
    cout << "Вызван деструктор класса Base" << endl;
}

Auto::Auto()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->cvet = "NONE";
    this->tipKPP = "NONE";

    cout << "Вызван конструктор по умолчанию класса - Auto" << endl;
}

Auto::Auto(string marka, string model, string obem_dvigatelya, string cvet, string tipKPP)
{
    this->marka = marka;
    this->model = model;
    this->obem_dvigatelya = obem_dvigatelya;
    this->cvet = cvet;
    this->tipKPP = tipKPP;

    cout << "Вызван конструктор с параметром класса - Auto" << endl;
}

Auto::Auto(const Auto& B)
{
    this->marka = B.marka;
    this->model = B.model;
    this->obem_dvigatelya = B.obem_dvigatelya;
    this->cvet = B.cvet;
    this->tipKPP = B.tipKPP;

    cout << "Вызван конструктор копирования класса - Auto" << endl;
}

Auto::~Auto()
{
    cout << "Вызван деструктор класса - Auto" << endl;
}

// основные методы
// метод установки значения
void Auto::Set()
{
    string buf;
    getline(cin, buf);

    cout << "Введите данные об авто:" << endl;

    cout << "Марка: ";
    getline(cin, this->marka);

    cout << "Модель: ";
    getline(cin, this->model);

    cout << "Объем двигателя: ";
    getline(cin, this->obem_dvigatelya);

    cout << "Цвет: ";
    getline(cin, this->cvet);

    cout << "Тип КПП: ";
    getline(cin, this->tipKPP);
}

// метод получения значений
void Auto::Get()
{
    cout << "_________Информация об авто" << endl;
    cout << "Марка: " << this->marka << endl;
    cout << "Модель: " << this->model << endl;
    cout << "Объем двигателя: " << this->obem_dvigatelya << endl;
    cout << "Цвет: " << this->cvet << endl;
    cout << "Тип кпп: " << this->tipKPP << endl;
    cout << "___________________________" << endl;
}

// метод удаления данных
void Auto::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->cvet = "NONE";
    this->tipKPP = "NONE";
}

// метод изменения данных
void Auto::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Марка \n"
        << "2 - Модель \n"
        << "3 - Объем двигателя \n"
        << "4 - Цвет \n"
        << "5 - Тип КПП \n"
        << "___________________________________" << endl;

    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' && choice[i] <= 'Z' || choice[i] >= 'a' && choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 || stoi(choice) > 5) throw "Error";
    }
    catch (const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch (const char* mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    string buf;
    getline(cin, buf);
    if (stoi(choice) == 1)
    {
        cout << "Марка: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "Модель: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "Объем двигателя: ";
        getline(cin, this->obem_dvigatelya);
    }
    else if (stoi(choice) == 4)
    {
        cout << "Цвет: ";
        getline(cin, this->cvet);
    }
    else
    {
        cout << "Тип КПП: ";
        getline(cin, this->tipKPP);
    }
}

Moto::Moto()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->moshnost = "NONE";
    this->tip_mestnosti = "NONE";

    cout << "Вызван конструктор по умолчанию класса - Moto" << endl;
}

Moto::Moto(string marka, string model, string obem_dvigatelya, string moshnost, string tip_mestnosti)
{
    this->marka = marka;
    this->model = model;
    this->obem_dvigatelya = obem_dvigatelya;
    this->moshnost = moshnost;
    this->tip_mestnosti = tip_mestnosti;

    cout << "Вызван конструктор с параметром класса - Moto" << endl;
}

Moto::Moto(const Moto& S)
{
    this->marka = S.marka;
    this->model = S.model;
    this->obem_dvigatelya = S.obem_dvigatelya;
    this->moshnost = S.moshnost;
    this->tip_mestnosti = S.tip_mestnosti;

    cout << "Вызван конструктор копирования класса - Moto" << endl;
}

// деструктор
Moto::~Moto()
{
    cout << "Вызван деструктор класса - Moto" << endl;
}

// метод установки значения
void Moto::Set()
{
    string buf;
    getline(cin, buf);

    cout << "Введите данные о мотоцикле:" << endl;

    cout << "Марка: ";
    getline(cin, this->marka);

    cout << "Модель: ";
    getline(cin, this->model);

    cout << "Объем двигателя: ";
    getline(cin, this->obem_dvigatelya);

    cout << "Мощность: ";
    getline(cin, this->moshnost);

    cout << "Тип местности: ";
    getline(cin, this->tip_mestnosti);
}

// метод получения значений
void Moto::Get()
{
    cout << "_______Иформация о мотоциклах" << endl;
    cout << "1 - Марка \n"
        << "2 - Модель \n"
        << "3 - Объем двигателя \n"
        << "4 - Мощность \n"
        << "5 - Тип местности \n"
        << "___________________________________" << endl;
}

// метод удаления данных
void Moto::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->moshnost = "NONE";
    this->tip_mestnosti = "NONE";
}

// метод изменения данных
void Moto::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Марка \n"
        << "2 - Модель \n"
        << "3 - Объем двигателя \n"
        << "4 - Мощность \n"
        << "5 - Тип местности \n"
        << "___________________________________" << endl;

    string choice;

    try
    {
        cin >> choice;
        for(int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' && choice[i] <= 'Z' || choice[i] >= 'a' && choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 || stoi(choice) > 7) throw "Error";
    }
    catch (const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch (const char* mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    string buf;
    getline(cin, buf);

   if (stoi(choice) == 1)
    {
        cout << "Марка: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "Модель: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "Объем двигателя: ";
        getline(cin, this->obem_dvigatelya);
    }
    else if (stoi(choice) == 4)
    {
        cout << "Мощность: ";
        getline(cin, this->moshnost);
    }
    else
    {
        cout << "Тип местности: ";
        getline(cin, this->tip_mestnosti);
    }
}

Bus::Bus()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->kolvo_sidiachih_mest = "NONE";
    this->obshee_kolvo_mest = "NONE";
    this->konechnii_punkt = "NONE";

    cout << "Вызван конструктор по умолчанию класса - Bus" << endl;
}

Bus::Bus(string marka, string model, string kolvo_sidiachih_mest, string obshee_kolvo_mest, string konechnii_punkt)
{
    this->marka = marka;
    this->model = model;
    this->kolvo_sidiachih_mest = kolvo_sidiachih_mest;
    this->obshee_kolvo_mest = obshee_kolvo_mest;
    this->konechnii_punkt = konechnii_punkt;

    cout << "Вызван конструктор с параметром класса - Bus" << endl;
}

Bus::Bus(const Bus& C)
{
    this->marka = C.marka;
    this->model = C.model;
    this->kolvo_sidiachih_mest = C.kolvo_sidiachih_mest;
    this->obshee_kolvo_mest = C.obshee_kolvo_mest;
    this->konechnii_punkt = C.konechnii_punkt;

    cout << "Вызван конструктор копирования класса - Bus" << endl;
}

Bus::~Bus()
{
    cout << "Вызван деструктор класса - Bus" << endl;
}

// метод установки значения
void Bus::Set()
{
    string buf;
    getline(cin, buf);

    cout << "Введите данные об автобусах:" << endl;

    cout << "Марка: ";
    getline(cin, this->marka);

    cout << "Модель: ";
    getline(cin, this->model);

    cout << "Колличество сидячих мест: ";
    getline(cin, this->kolvo_sidiachih_mest);

    cout << "Общее колличество мест: ";
    getline(cin, this->obshee_kolvo_mest);

    cout << "Конечный пункт: ";
    getline(cin, this->konechnii_punkt);
}

// метод получения значений
void Bus::Get()
{
    cout << "_______Иформация об автобусах" << endl;
    cout << "1 - Марка \n"
        << "2 - Модель \n"
        << "3 - Колличество сидячих мест \n"
        << "4 - Общее колличество мест \n"
        << "5 - Конечный пункт \n"
        << "___________________________________" << endl;
}

// метод удаления данных
void Bus::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->kolvo_sidiachih_mest = "NONE";
    this->obshee_kolvo_mest = "NONE";
    this->konechnii_punkt = "NONE";
}

// метод изменения данных
void Bus::Change()
{
    cout << "Выберите, что вы хотите изменить:" << endl;
    cout << "1 - Марка \n"
        << "2 - Модель \n"
        << "3 - Колличество сидячих мест \n"
        << "4 - Общее колличество мест \n"
        << "5 - Конечный пункт \n"
        << "___________________________________" << endl;

    string choice;

    try
    {
        cin >> choice;
        for (int i = 0; i < choice.length(); i++)
        {
            if (choice[i] >= 'A' && choice[i] <= 'Z' || choice[i] >= 'a' && choice[i] <= 'z') throw "Error";
        }
        if (stoi(choice) < 1 || stoi(choice) > 4) throw "Error";
    }
    catch (const std::exception& e)
    {
        cout << "Некорректный ввод" << endl;
    }
    catch (const char* mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    string buf;
    getline(cin, buf);

    if (stoi(choice) == 1)
    {
        cout << "Марка: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "Модель: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "Объем двигателя: ";
        getline(cin, this->kolvo_sidiachih_mest);
    }
    else if (stoi(choice) == 4)
    {
        cout << "Мощность: ";
        getline(cin, this->obshee_kolvo_mest);
    }
    else
    {
        cout << "Тип местности: ";
        getline(cin, this->konechnii_punkt);
    }
}

// методты GetType

int Auto::TypeID()
{
    return 1;
}
int Moto::TypeID()
{
    return 2;
}
int Bus::TypeID()
{
    return 3;
}

string Auto::Save(int count)
{
    if (count == 0) return this->marka;
    else if (count == 1) return this->model;
    else if (count == 2) return this->obem_dvigatelya;
    else if (count == 3) return this->cvet;
    else if (count == 4) return this->tipKPP;
}

string Moto::Save(int count)
{
    if (count == 0) return this->marka;
    else if (count == 1) return this->model;
    else if (count == 2) return this->obem_dvigatelya;
    else if (count == 3) return this->moshnost;
    else if (count == 4) return this->tip_mestnosti;
}

string Bus::Save(int count)
{
    if (count == 0) return this->marka;
    else if (count == 1) return this->model;
    else if (count == 2) return this->kolvo_sidiachih_mest;
    else if (count == 3) return this->obshee_kolvo_mest;
    else if (count == 4) return this->konechnii_punkt;
}

void Auto::Load(int count, string line)
{
    if (count == 0) this->marka = marka;
    else if (count == 1) this->model = model;
    else if (count == 2) this->obem_dvigatelya = obem_dvigatelya;
    else if (count == 3) this->cvet = cvet;
    else if (count == 4) this->tipKPP = tipKPP;
}

void Moto::Load(int count, string line)
{
    if (count == 0) this->marka = marka;
    else if (count == 1) this->model = model;
    else if (count == 2) this->obem_dvigatelya = obem_dvigatelya;
    else if (count == 3) this->moshnost = moshnost;
    else if (count == 4) this->tip_mestnosti = tip_mestnosti;
}

void Bus::Load(int count, string line)
{
    if (count == 0) this->marka = marka;
    else if (count == 1) this->model = model;
    else if (count == 2) this->kolvo_sidiachih_mest = kolvo_sidiachih_mest;
    else if (count == 3) this->obshee_kolvo_mest = obshee_kolvo_mest;
    else if (count == 4) this->konechnii_punkt = konechnii_punkt;
}