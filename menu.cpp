using namespace std;
#include <iostream>

#include "Keeper.h"
#include "baseClass.h"



void workMenu(void);
void menuForAuto(void);
void menuForMoto(void);
void menuForBus(void);
int main(void) {
	Keeper keeper;
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		string command;
		workMenu();
		try {
			cin >> command;
			if (command != "0" && command != "1" && command != "2" && command != "3" && command != "4" && command != "5") throw "Errand";
		}
		catch (const std::exception& e) {
			cout << "�������� ����" << endl;
		}
		catch (const char* mssg) {
			cout << "�������� �����" << endl;
			break;
		}
		if (command == "0") {
			workMenu();
			break;
		}
		else if (command == "1") {
			keeper.Set();
		}
		else if (command == "2") {
			keeper.GetAll();
		}
		else if (command == "3") {
			keeper.GetChoice();
		}
		else if (command == "4") {
			keeper.Delete();
		}
		else if (command == "5") {
			keeper.Change();
		}
		else if (command == "6") {
			keeper.loadK();
		}
		else{
			keeper.saveK();
		}
	}
		system("pause");
}


void workMenu(void) {
	system("cls");
	cout << "0 - ������\n"
		"1 - �������� �������\n"
		"2 - �������� �������� ���� ���������\n"
		"3 - �������� �������� ���������� ��������\n"
		"4 - ������� �������\n"
		"5 - �������� �������\n"
		"6 - ��������� ������ �� �����\n"
		"7 - ��������� ������ � ����"<<endl;

}
void menuForAuto(void) {
	system("cls");
	cout << "������ � ������� �� �����������:\n"
		"1 - ��������� ������ �� �����\n"
		"2 - �������� ������ � �����\n"
		"3 - ������ ������ � ����� �����������\n"
		"4 - �������� ������ � ����������� �����������\n"
		"5 - ���������\n";
}
void menuForMoto(void) {
	system("cls");
	cout << "������ � ������� � ����������:\n"
		"1 - ��������� ������ �� �����\n"
		"2 - �������� ������ � �����\n"
		"3 - ������ ������ � ����� ����������\n"
		"4 - �������� ������ � ����������� ����������\n"
		"5 - ���������\n";
}
void menuForBus(void) {
	system("cls");
	cout << "������ � ������� �� ���������:\n"
		"1 - ��������� ������ �� �����\n"
		"2 - �������� ������ � �����\n"
		"3 - ������ ������ � ����� ���������\n"
		"4 - �������� ������ � ����������� ���������\n"
		"5 - ���������\n";
}