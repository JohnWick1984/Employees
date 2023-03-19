// Employees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

struct Employee
{
	char surname{ NULL };
	char name{ NULL };
	int age{ NULL };
	string profession{ NULL };
	
} Employees[1000];

void DisplayEmploees(int k)
{
	cout << "Фамилия сотрудника: " << Employees[k].surname << "\n";
	cout << "Имя сотрудника: " << Employees[k].name << "\n";
	cout << "Возраст сотрудника: " << Employees[k].age << "\n";
	cout << "Профессия сотрудника: " << Employees[k].profession << "\n";
}

void SearchName(int k, char name)
{
	int count{ 0 };
	for (int i = 1; i <= k; i++)
	{
		if (Employees[i].name == name)
		{
			count++;
			DisplayEmploees(i);
			cout << "\n";
		}
	}
	if (count == 0)
	{
		cout << "Ничего не найдено.\n\n";
	}
}
void editEmployee(Employee employees[], int k) 
{
    char name[1000];
	cout << "Введите фамилию сотрудника, которого хотите изменить: ";
	cin >> name;
	for (int i = 0; i < k; i++) 
	{
		if (strcmp(employees[i].name,name) == 0)
		{
			cout << "Введите новую фамилию: ";
			cin >> Employees[i].name;
			cout << "Введите новый возраст: ";
			cin >> Employees[i].age;
			cout << "Введите новую должность: ";
			cin >> Employees[i].profession;
			cout << "Сотрудник успешно изменен" << endl;
			return;
		}
	}
	cout << "Сотрудник с такой фамилией не найден" << endl;
}

void AddInfo(int k)
{
	cout << "Введите данные о сотруднике: \n\n";
	cout << "ФИО: ";
	cin >> Employees[k].name;
	cout << "Возраст: ";
	cin >> Employees[k].age;
	cout << "Обьем двигателя: ";
	cin >> Employees[k].profession;
	

}




int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int answer_id{ 0 }, k{ 2 }, name{ 0 };
	string name_ch{ NULL };

	Employees[1] = { "Иванов Петр Сидорович", 30, "Слесарь"};
	Employees[2] = { " Петрова Лада Калиньевна", 45, "Тиктокарь" };

	while (answer_id != 5)
	{
		system("cls");

		cout << "***Список сотрудников***\n\n";

		cout << "- 1 - Добавить запись.\n";
		cout << "- 2 - Вывести весь список.\n";
		cout << "- 3 - Поиск по Фамилии.\n";
		cout << "- 4 - Поиск по возрасту.\n";
		cout << "- 5 - Выход.\n";

		cin >> answer_id;
		system("cls");

		switch (answer_id)
		{
		case(1):
			k++;
			AddInfo(k);
			break;

		case(2):
			for (int i = 1; i <= k; i++)
			{
				DisplayEmploees(i);
			}
			system("pause");
			break;

		case(3):
			cout << "Введите фамилию сотрудника: ";
			cin >> name_ch;
			cout << "\n";
			SearchName(k, name_ch);
			system("pause");
			break;



		default:
			break;
		}
	}

	return 0;
}