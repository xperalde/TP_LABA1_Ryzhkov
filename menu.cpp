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
	cout << "0 - Помощь\n"
		"1 - Работа с данными об автомобилях\n"
		"2 - Работа с данными о мотоциклах\n"
		"3 - Работа с данными об автобусах\n";
}
void menuForAuto(void) {
	system("cls");
	cout << "Работа с данными об автомобилях:\n"
		"1 - Загрузить данные из файла\n"
		"2 - Очистить данные в файле\n"
		"3 - Ввести данные о новых автомобилях\n"
		"4 - Показать данные о сохраненных автомобилях\n"
		"5 - Вернуться\n";
}
void menuForMoto(void) {
	system("cls");
	cout << "Работа с данными о мотоциклах:\n"
		"1 - Загрузить данные из файла\n"
		"2 - Очистить данные в файле\n"
		"3 - Ввести данные о новых мотоциклах\n"
		"4 - Показать данные о сохраненных мотоциклах\n"
		"5 - Вернуться\n";
}
void menuForBus(void) {
	system("cls");
	cout << "Работа с данными об автобусах:\n"
		"1 - Загрузить данные из файла\n"
		"2 - Очистить данные в файле\n"
		"3 - Ввести данные о новых автобусах\n"
		"4 - Показать данные о сохраненных автобусах\n"
		"5 - Вернуться\n";
}