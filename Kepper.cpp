#include <iostream>
#include <string>
#include <fstream>
#include "Keeper.h"
#include "baseClass.h"
using namespace std;

Keeper::Keeper() {
	this->array = new Base * [1];
	this->size = 1;
	this->count_element = 0;
	cout << "������ ����������� ��� ��������� ������ Keeper" << endl;
}

Keeper::Keeper(int size) {
	this->array = new Base * [size];
	this->size = size;
	this->count_element = 0;
	cout << "������ ����������� � ���������� ������ Keeper" << endl;
}

Keeper::Keeper(const Keeper &K) {
	this->size = K.size;
	this->count_element = K.count_element;
	this->array = new Base * [this->size];
	for (int count = 0; count < count_element; count++) {
		this->array[count] = K.array[count];
	}
	cout << "������ ����������� ����������� ������ Keeper" << endl;
}

Keeper::~Keeper(){
	delete[] this->array;
	cout << "������ ��������� ������ Keeper" << endl;
}

// ����� ���������� ��������
void Keeper::Set() {
	cout << "1 - ����������\n"
		"2 - ��������\n"
		"3 - �������\n" << endl;
	string choice;

	try
	{
		cin >> choice;
		for (int i = 0; i < choice.length(); i++)
		{
			if (choice[i] >= 'A' && choice[i] <= 'Z' || choice[i] >= 'a' && choice[i] <= 'z') throw "Error";
		}
		if (stoi(choice) < 1 || stoi(choice) > 3) throw "Err||";
	}
	catch (const std::exception& e)
	{
		cout << "������������ ����" << endl;
	}
	catch (const char* mssg)
	{
		cout << "�������� �����" << endl;
	}

	// ���� ������ ����������
	if (this->count_element == this->size)
	{
		Base** buf_array = new Base * [size]; // ������� �������� ������ ��� ����������� ��������

		for (int count = 0; count < size; count++)
		{
			buf_array[count] = this->array[count]; // �������� ��������
		}

		delete[] this->array; // ������� ������ ��� ������

		// �������� ����� ������ ��� ��� ������
		try
		{
			this->array = new Base * [size * 2]; // �������� ���. ������
		}
		catch (const std::exception& e)
		{
			std::cerr << "������ �� ������� ��������" << endl;
			exit(1);
		}

		this->size = size * 2; // ����������� ������ �������

		// �������� ������ ��������
		for (int count = 0; count < count_element; count++)
		{
			this->array[count] = buf_array[count]; // �������� ��������
		}
	}

	if (stoi(choice) == 1)
	{
		Base* ptr_Auto = new Auto();
		array[count_element++] = ptr_Auto;
		ptr_Auto->Set();
	}

	else if (stoi(choice) == 2)
	{
		Base* ptr_Moto = new Moto();
		array[count_element++] = ptr_Moto;
		ptr_Moto->Set();
	}

	else
	{
		Base* ptr_Bus = new Bus();
		array[count_element++] = ptr_Bus;
		ptr_Bus->Set();
	}
}

// ����� ���������
void Keeper::Change() {
	cout << "������� ����� �������� ������� �� ������ ��������" << endl;
	string id;
	try {
		cin >> id;
		for (int i = 0; i < id.length(); i++) {
			if ((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= 'a' && id[i] <= 'z')) throw "Error";
		}
		if (stoi(id) > count_element || stoi(id) < 0) throw "Error";
		if (count_element == 0 && stoi(id) == 0) throw "Error";
	}
	catch (const std::exception& e) {
		cout << "������������ ����" << endl;
		exit(1);
	}
	catch (const char* mssg) {
		cout << "�������� �����" << endl;
		exit(1);
	}
	array[stoi(id)]->Change();
}

// ����� ��������� ���������
void Keeper::Get()
{
	cout << "������:" << endl;
	for (int count = 0; count < count_element; count++)
	{
		array[count]->Get();
	}
}

// ����� ��������� ���������
void Keeper::GetChoice()
{
	cout << "������� �����, ������� �� ������ �������: ";
	string id;
	try
	{
		cin >> id;
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 'A' && id[i] <= 'Z' || id[i] >= 'a' && id[i] <= 'z') throw "Error";
		}
		if (stoi(id) > count_element || stoi(id) < 0) throw "Error";
	}
	catch (const std::exception& e)
	{
		cout << "������������ ����" << endl;
	}
	catch (const char* mssg)
	{
		cout << "�������� �����" << endl;
	}

	array[stoi(id)]->Get();
}

Keeper& Keeper::operator-=(int element)
{
	// �������� ��� ��������

	for (int count = element; count < count_element - 1; count++)
	{
		int buf_count = count + 1;
		array[count] = array[buf_count];
	}
	this->count_element--;
	return *this;
}

void Keeper::Save()
{
	cout << "\nSAVE" << endl;

	ofstream loadB;
	ofstream loadS;
	ofstream loadC;
	loadB.open("Auto.txt");
	loadS.open("Moto.txt");
	loadC.open("Bus.txt");

	int countB = 0;
	int countS = 0;
	int countC = 0;

	for (int i = 0; i < count_element; i++)
	{
		if (this->array[i]->TypeID() == 1)
		{
			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB++;

			loadB << this->array[i]->Save(countB) << endl;
			countB = 0;
		}

		else if (this->array[i]->TypeID() == 2)
		{
			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS++;

			loadS << this->array[i]->Save(countS) << endl;
			countS = 0;
		}

		else if (this->array[i]->TypeID() == 3)
		{
			loadC << this->array[i]->Save(countC) << endl;
			countC++;

			loadC << this->array[i]->Save(countC) << endl;
			countC++;

			loadC << this->array[i]->Save(countC) << endl;
			countC++;

			loadC << this->array[i]->Save(countC) << endl;
			countC = 0;
		}
	}

	cout << "\nSAVE COMPLETE" << endl;

	loadB.close();
	loadS.close();
	loadC.close();
}

// ����� �������������� �� �����
void Keeper::Load()
{
	cout << "\nLOAD" << endl;

	ifstream loadB;
	ifstream loadS;
	ifstream loadC;
	loadB.open("Auto.txt");
	loadS.open("Moto.txt");
	loadC.open("Bus.txt");

	if (loadB.is_open() && loadS.is_open() && loadC.is_open())
	{
		string line; // ������, � ������� ����� ���������
		int count = 0; // ������� ��� ������

		while (true)
		{
			if (!getline(loadB, line)) break;

			Base* ptr_Auto = new Auto(); // ������� ������ - �������

			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);
			count++;

			getline(loadB, line);
			ptr_Auto->Load(count, line);

			count = 0;

			this->array[count_element++] = ptr_Auto; // ��������� � ������
		}

		count = 0; // ������� ��� ������

		while (true)
		{
			if (!getline(loadS, line)) break;

			Base* ptr_Moto = new Moto(); // ������� ������ - �������

			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);
			count++;

			getline(loadS, line);
			ptr_Moto->Load(count, line);

			count = 0;

			this->array[count_element++] = ptr_Moto; // ��������� � ������
		}

		count = 0; // ������� ��� ������

		while (true)
		{
			if (!getline(loadC, line)) break;

			Base* ptr_Bus = new Bus(); // ������� ������ - �������

			ptr_Bus->Load(count, line);
			count++;

			getline(loadC, line);
			ptr_Bus->Load(count, line);
			count++;

			getline(loadC, line);
			ptr_Bus->Load(count, line);
			count++;

			getline(loadC, line);
			ptr_Bus->Load(count, line);

			count = 0;

			this->array[count_element++] = ptr_Bus; // ��������� � ������
		}

		cout << "\nLOAD COMPLETE" << endl;
	}

	else
	{
		cout << "\n������ �������� ������" << endl;
	}

	loadB.close();
	loadS.close();
	loadC.close();
}
