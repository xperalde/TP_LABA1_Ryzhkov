using namespace std;
#include <iostream>
#include <vector>
#include <fstream>



void workMenu(void);
void menuForAuto(void);
void menuForMoto(void);
void menuForBus(void);
int main(void) {
	setlocale(LC_ALL, "Russian");
	int command;
	while (1)
	{
		workMenu();
		cin >> command;
		switch (command)
		{
		case 0:
			workMenu();
			break;
		case 1:
			menuForAuto();
			cin >> command;
			if (command == 1) {
				break;
			}
			else if (command == 2) {
				break;
			}
			else if (command == 3) {
				break;
			}
			else if (command == 4) {
				break;
			}
			else {
				system("cls");
				workMenu();
				break;
			}
		case 2:
			menuForMoto();
			if (command == 1) {
				break;
			}
			else if (command == 2) {
				break;
			}
			else if (command == 3) {
				break;
			}
			else if (command == 4) {
				break;
			}
			else{
				system("cls");
				workMenu();
				break;
			}
		case 3:
			menuForBus();
			if (command == 1) {
				break;
			}
			else if (command == 2) {
				break;
			}
			else if (command == 3) {
				break;
			}
			else if (command == 4) {
				break;
			}
			else {
				workMenu();
				break;
			}
		}
		system("pause");
	}
}

void workMenu(void) {
	system("cls");
	cout << "0 - ������\n"
		"1 - ������ � ������� �� �����������\n"
		"2 - ������ � ������� � ����������\n"
		"3 - ������ � ������� �� ���������\n";
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