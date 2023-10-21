#include <iostream>
#include <string>
#include "Keeper.h"
#include "baseClass.h"
using namespace std;

Keeper::Keeper() {
	this->array_with_element = new Base * [1];
	this->size = 1;
	this->count_element = 0;
	cout << "Вызван конструктор без параметра класса Keeper" << endl;
}

Keeper::Keeper(int size) {
	this->array_with_element = new Base * [size];
	this->size = size;
	this->count_element = 0;
	cout << "Вызван конструктор с параметром класса Keeper" << endl;
}

Keeper::Keeper(const Keeper &K) {
	this->size = K.size;
	this->count_element = K.count_element;
	this->array_with_element = new Base * [this->size];
	for (int count = 0; count < count_element; count++) {
		this->array_with_element[count] = K.array_with_element[count];
	}
	cout << "Вызван конструктор копирования класса Keeper" << endl;
}

Keeper::~Keeper(){
	delete[] this->array_with_element;
	cout << "вызван деструтор класса Keeper" << endl;
}

void Keeper::Set() {
	cout << "1 - Автомобиль\n"
		"2 - Мотоцикл\n"
		"3 - Автобус\n" << endl;
	string choice;
	try {
		cin >> choice;
		if (choice != "1" && choice != "2" && choice != "3") throw "Error";
	}
	catch (const std::exception& e) {
		cout << "Некорректный ввод" << endl;
		exit(1);
	}
	catch (const char* mssg) {
		cout << "Неверный выбор" << endl;
		exit(1);
	}
	if (choice == "1") {
		Base* ptr_auto = new Auto();
		ptr_auto->Set();
		this->array_with_element[count_element++] = ptr_auto;
	}
	else if (choice == "2"){
		Base* ptr_moto = new Moto();
			ptr_moto->Set();
			this->array_with_element[count_element++] = ptr_moto;
	}
	else{
		Base* ptr_bus = new Bus();
		ptr_bus->Set();
		this->array_with_element[count_element++] = ptr_bus;
	}
}

void Keeper::Change() {
	cout << "Введите номер элемента который вы хотите изменить" << endl;
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
		cout << "Некорректный ввод" << endl;
		exit(1);
	}
	catch (const char* mssg) {
		cout << "Неверный выбор" << endl;
		exit(1);
	}
	array_with_element[stoi(id)]->Change();
}