using namespace std;
#include <iostream>

#include "Keeper.h"
#include "baseClass.h"



void workMenu(void);
int main(void) {
	Keeper keeper;
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		string command;
		workMenu();
		try {
			cin >> command;
			if (command != "0" && command != "1" && command != "2" && command != "3" && command != "4" && command != "5" && command != "6" && command != "7") throw "Errand";
		}
		catch (const std::exception& e) {
			cout << "Неверный ввод" << endl;
		}
		catch (const char* mssg) {
			cout << "Неверный выбор" << endl;
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
			keeper.Get();
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
			keeper.Load();
		}
		else{
			keeper.Save();
		}
	}
		system("pause");
}


void workMenu(void) {
	system("cls");
	cout << "0 - Помощь\n"
		"1 - Добавить элемент\n"
		"2 - Получить значения всех элементов\n"
		"3 - Получить значения выбранного элемента\n"
		"4 - Удалить элемент\n"
		"5 - Изменить элемент\n"
		"6 - Загрузить данные из файла\n"
		"7 - Загрузить данные в файл"<<endl;

}