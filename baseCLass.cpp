#include <iostream>
#include "baseClass.h"

using namespace std;

Base::Base()
{
    cout << "������ ����������� ������ Base" << endl;
}
Base::Base(int size)
{
    cout << "������ ����������� � ���������� ������ Base" << endl;
}
Base::Base(const Base& B)
{
    cout << "������ ����������� ����������� ������ Base" << endl;
}
Base::~Base()
{
    cout << "������ ���������� ������ Base" << endl;
}

Auto::Auto()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->cvet = "NONE";
    this->tipKPP = "NONE";

    cout << "������ ����������� �� ��������� ������ - Auto" << endl;
}

Auto::Auto(string marka, string model, string obem_dvigatelya, string cvet, string tipKPP)
{
    this->marka = marka;
    this->model = model;
    this->obem_dvigatelya = obem_dvigatelya;
    this->cvet = cvet;
    this->tipKPP = tipKPP;

    cout << "������ ����������� � ���������� ������ - Auto" << endl;
}

Auto::Auto(const Auto& B)
{
    this->marka = B.marka;
    this->model = B.model;
    this->obem_dvigatelya = B.obem_dvigatelya;
    this->cvet = B.cvet;
    this->tipKPP = B.tipKPP;

    cout << "������ ����������� ����������� ������ - Auto" << endl;
}

Auto::~Auto()
{
    cout << "������ ���������� ������ - Auto" << endl;
}

// �������� ������
// ����� ��������� ��������
void Auto::Set()
{
    string buf;
    getline(cin, buf);

    cout << "������� ������ �� ����:" << endl;

    cout << "�����: ";
    getline(cin, this->marka);

    cout << "������: ";
    getline(cin, this->model);

    cout << "����� ���������: ";
    getline(cin, this->obem_dvigatelya);

    cout << "����: ";
    getline(cin, this->cvet);

    cout << "��� ���: ";
    getline(cin, this->tipKPP);
}

// ����� ��������� ��������
void Auto::Get()
{
    cout << "_________���������� �� ����" << endl;
    cout << "�����: " << this->marka << endl;
    cout << "������: " << this->model << endl;
    cout << "����� ���������: " << this->obem_dvigatelya << endl;
    cout << "����: " << this->cvet << endl;
    cout << "��� ���: " << this->tipKPP << endl;
    cout << "___________________________" << endl;
}

// ����� �������� ������
void Auto::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->cvet = "NONE";
    this->tipKPP = "NONE";
}

// ����� ��������� ������
void Auto::Change()
{
    cout << "��������, ��� �� ������ ��������:" << endl;
    cout << "1 - ����� \n"
        << "2 - ������ \n"
        << "3 - ����� ��������� \n"
        << "4 - ���� \n"
        << "5 - ��� ��� \n"
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
        cout << "������������ ����" << endl;
    }
    catch (const char* mssg)
    {
        cout << "�������� ����" << endl;
    }

    string buf;
    getline(cin, buf);
    if (stoi(choice) == 1)
    {
        cout << "�����: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "������: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "����� ���������: ";
        getline(cin, this->obem_dvigatelya);
    }
    else if (stoi(choice) == 4)
    {
        cout << "����: ";
        getline(cin, this->cvet);
    }
    else
    {
        cout << "��� ���: ";
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

    cout << "������ ����������� �� ��������� ������ - Moto" << endl;
}

Moto::Moto(string marka, string model, string obem_dvigatelya, string moshnost, string tip_mestnosti)
{
    this->marka = marka;
    this->model = model;
    this->obem_dvigatelya = obem_dvigatelya;
    this->moshnost = moshnost;
    this->tip_mestnosti = tip_mestnosti;

    cout << "������ ����������� � ���������� ������ - Moto" << endl;
}

Moto::Moto(const Moto& S)
{
    this->marka = S.marka;
    this->model = S.model;
    this->obem_dvigatelya = S.obem_dvigatelya;
    this->moshnost = S.moshnost;
    this->tip_mestnosti = S.tip_mestnosti;

    cout << "������ ����������� ����������� ������ - Moto" << endl;
}

// ����������
Moto::~Moto()
{
    cout << "������ ���������� ������ - Moto" << endl;
}

// ����� ��������� ��������
void Moto::Set()
{
    string buf;
    getline(cin, buf);

    cout << "������� ������ � ���������:" << endl;

    cout << "�����: ";
    getline(cin, this->marka);

    cout << "������: ";
    getline(cin, this->model);

    cout << "����� ���������: ";
    getline(cin, this->obem_dvigatelya);

    cout << "��������: ";
    getline(cin, this->moshnost);

    cout << "��� ���������: ";
    getline(cin, this->tip_mestnosti);
}

// ����� ��������� ��������
void Moto::Get()
{
    cout << "_______��������� � ����������" << endl;
    cout << "1 - ����� \n"
        << "2 - ������ \n"
        << "3 - ����� ��������� \n"
        << "4 - �������� \n"
        << "5 - ��� ��������� \n"
        << "___________________________________" << endl;
}

// ����� �������� ������
void Moto::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->obem_dvigatelya = "NONE";
    this->moshnost = "NONE";
    this->tip_mestnosti = "NONE";
}

// ����� ��������� ������
void Moto::Change()
{
    cout << "��������, ��� �� ������ ��������:" << endl;
    cout << "1 - ����� \n"
        << "2 - ������ \n"
        << "3 - ����� ��������� \n"
        << "4 - �������� \n"
        << "5 - ��� ��������� \n"
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
        cout << "������������ ����" << endl;
    }
    catch (const char* mssg)
    {
        cout << "�������� ����" << endl;
    }

    string buf;
    getline(cin, buf);

   if (stoi(choice) == 1)
    {
        cout << "�����: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "������: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "����� ���������: ";
        getline(cin, this->obem_dvigatelya);
    }
    else if (stoi(choice) == 4)
    {
        cout << "��������: ";
        getline(cin, this->moshnost);
    }
    else
    {
        cout << "��� ���������: ";
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

    cout << "������ ����������� �� ��������� ������ - Bus" << endl;
}

Bus::Bus(string marka, string model, string kolvo_sidiachih_mest, string obshee_kolvo_mest, string konechnii_punkt)
{
    this->marka = marka;
    this->model = model;
    this->kolvo_sidiachih_mest = kolvo_sidiachih_mest;
    this->obshee_kolvo_mest = obshee_kolvo_mest;
    this->konechnii_punkt = konechnii_punkt;

    cout << "������ ����������� � ���������� ������ - Bus" << endl;
}

Bus::Bus(const Bus& C)
{
    this->marka = C.marka;
    this->model = C.model;
    this->kolvo_sidiachih_mest = C.kolvo_sidiachih_mest;
    this->obshee_kolvo_mest = C.obshee_kolvo_mest;
    this->konechnii_punkt = C.konechnii_punkt;

    cout << "������ ����������� ����������� ������ - Bus" << endl;
}

Bus::~Bus()
{
    cout << "������ ���������� ������ - Bus" << endl;
}

// ����� ��������� ��������
void Bus::Set()
{
    string buf;
    getline(cin, buf);

    cout << "������� ������ �� ���������:" << endl;

    cout << "�����: ";
    getline(cin, this->marka);

    cout << "������: ";
    getline(cin, this->model);

    cout << "����������� ������� ����: ";
    getline(cin, this->kolvo_sidiachih_mest);

    cout << "����� ����������� ����: ";
    getline(cin, this->obshee_kolvo_mest);

    cout << "�������� �����: ";
    getline(cin, this->konechnii_punkt);
}

// ����� ��������� ��������
void Bus::Get()
{
    cout << "_______��������� �� ���������" << endl;
    cout << "1 - ����� \n"
        << "2 - ������ \n"
        << "3 - ����������� ������� ���� \n"
        << "4 - ����� ����������� ���� \n"
        << "5 - �������� ����� \n"
        << "___________________________________" << endl;
}

// ����� �������� ������
void Bus::Delete()
{
    this->marka = "NONE";
    this->model = "NONE";
    this->kolvo_sidiachih_mest = "NONE";
    this->obshee_kolvo_mest = "NONE";
    this->konechnii_punkt = "NONE";
}

// ����� ��������� ������
void Bus::Change()
{
    cout << "��������, ��� �� ������ ��������:" << endl;
    cout << "1 - ����� \n"
        << "2 - ������ \n"
        << "3 - ����������� ������� ���� \n"
        << "4 - ����� ����������� ���� \n"
        << "5 - �������� ����� \n"
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
        cout << "������������ ����" << endl;
    }
    catch (const char* mssg)
    {
        cout << "�������� ����" << endl;
    }

    string buf;
    getline(cin, buf);

    if (stoi(choice) == 1)
    {
        cout << "�����: ";
        getline(cin, this->marka);
    }
    else if (stoi(choice) == 2)
    {
        cout << "������: ";
        getline(cin, this->model);
    }
    else if (stoi(choice) == 3)
    {
        cout << "����� ���������: ";
        getline(cin, this->kolvo_sidiachih_mest);
    }
    else if (stoi(choice) == 4)
    {
        cout << "��������: ";
        getline(cin, this->obshee_kolvo_mest);
    }
    else
    {
        cout << "��� ���������: ";
        getline(cin, this->konechnii_punkt);
    }
}

// ������� GetType

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