// var3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// -*- coding: utf-8 -*-
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

struct Employee 
{
    string surname;
    string name;
    int age;
    string profession;
};
int employeeCount = 4;
Employee Employees[1000];

void WriteToFile(int employeeCount)
{
    ofstream outFile("employees.txt"); 
    if (outFile.is_open())
    {
        for (int i = 0; i <= employeeCount; i++)
        {
            outFile << Employees[i].surname << " "
                << Employees[i].name << " "
                << Employees[i].age << " "
                << Employees[i].profession << "\n";
        }
        outFile.close(); 
    }
    else
    {
        cout << "Не удалось открыть файл для записи\n";
    }
}

void AddInfo(int employeeCount)
{
    cout << "Введите данные о сотруднике: \n\n";
    cout << "Фамилия: ";
    cin >> Employees[employeeCount].surname;
    cout << "Имя: ";
    cin >> Employees[employeeCount].name;
    cout << "Возраст: ";
    cin >> Employees[employeeCount].age;
    cout << "Должность: ";
    cin >> Employees[employeeCount].profession;


}
void DisplayEmployee(int employeeCount)
{
    cout << "Фамилия сотрудника: " << Employees[employeeCount].surname << "\n";
    cout << "Имя сотрудника: " << Employees[employeeCount].name << "\n";
    cout << "Возраст сотрудника: " << Employees[employeeCount].age << "\n";
    cout << "Профессия сотрудника: " << Employees[employeeCount].profession << "\n";
}

void SearchName(int employeeCount, string surname)
{
    int count{ 0 };
    for (int i = 0; i < employeeCount; i++)
    {
        if (Employees[i].surname == surname) 
        {
            count++;
            DisplayEmployee(i);
            cout << "\n";
        }
    }
    if (count == 0) 
    {
        cout << "Ничего не найдено.\n\n";
    }
}

void editEmployee(Employee employees[], int employeeCount)
{
    string surname;
    cout << "Введите фамилию сотрудника, которого хотите изменить: ";
    cin >> surname;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].name == surname)
        {
            cout << "Введите новую фамилию: ";
            cin >> Employees[i].surname;
            cout << "Введите новое имя: ";
            cin >> Employees[i].name;
            cout << "Введите новый возраст: ";
            cin >> Employees[i].age;
            cout << "Введите новую должность: ";
            cin >> Employees[i].profession;
            cout << "Сотрудник успешно изменен" << "\n";
            return;
        }
    }
    cout << "Сотрудник с такой фамилией не найден" << "\n";
}

void deleteEmployee() 
{
    string surname;
    cout << "Введите Фамилию сотрудника, которого хотите удалить из списка: ";
    cin >> surname;
    int index = -1;
    for (int i = 0; i < employeeCount; i++)
    {
        if (Employees[i].surname == surname)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Сотрудник с такой фамилией не найден" << "\n";
        return;
    }
    for (int i = index; i < employeeCount - 1; i++)
    {
        Employees[i] = Employees[i + 1];
    }
    employeeCount--;
    cout << "Сотрудник удален!" << "\n";
}
void SearchByAge(Employee employees[], int employeeCount)
{
    int age;
    cout << "Введите возраст для поиска: ";
    cin >> age;
    ofstream outfile("search_result.txt");
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].age == age) 
        {
            cout << employees[i].name << "\n";
        }
    }
    outfile.close();
}

void SearchByLetter(Employee employees[], int employeeCount)
{
    char letter;
    cout << "Введите первую букву фамилии для поиска: ";
    cin >> letter;
    ofstream outfile("search_result2.txt");
    for (int i = 0; i < employeeCount; i++) {
        if (tolower(employees[i].surname[0]) ==tolower(letter))
        {
            cout << employees[i].surname << "\n" << employees[i].name << "\n" << employees[i].age << "\n" << employees[i].profession << "\n";
        }
    }
    outfile.close();
}




int main() 
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int answer_id{ 0 };
    string nameSr{ NULL };
    ofstream out("D:\\employees.txt");

    if (out.is_open())
    {
        for (int i = 0; i < employeeCount; i++)
        {
            out << Employees[i].surname << "\n" << Employees[i].name << "\n" << Employees[i].age << "\n" << Employees[i].profession << "\n";
        }
    }
    out.close();

    Employees[0] = { "Иванов","Петр", 30, "Слесарь" };
    Employees[1] = { "Петрова","Лада", 45, "Тиктокарь" };
    Employees[2] = { "Сидоров", "Матвей" , 45, "Инженер" };
    Employees[3] = { "Петров", "Акакий", 45, "Контролер" };

    while (answer_id != 8)
    {
        

        cout << "***Список сотрудников***\n\n";

        cout << "- 1 - Добавить запись о сотруднике.\n";
        cout << "- 2 - Удалить запись о сотруднике.\n";
        cout << "- 3 - Редактировать запись о сотруднике.\n";
        cout << "- 4 - Вывести весь список.\n";
        cout << "- 5 - Поиск по Фамилии.\n";
        cout << "- 6 - Вывод сотрудников одного возраста.\n";
        cout << "- 7 - Вывод сотрудников по фамилиям на определенную букву.\n";
        cout << "- 8 - Выход.\n";

        cin >> answer_id;
        

        switch (answer_id)
        {
        case(1):
            AddInfo(employeeCount);
            employeeCount++;
            WriteToFile(employeeCount);
            break;
        case(2):
            deleteEmployee();
            WriteToFile(employeeCount);
            break;
        case(3):
            editEmployee(Employees, employeeCount);
            break;
            WriteToFile(employeeCount);
        case(4):
            for (int i = 0; i < employeeCount; i++)
            {
                DisplayEmployee(i);
            }
            system("pause");
            break;
        case(5):
            cout << "Введите фамилию сотрудника: ";
            cin >> nameSr;
            cout << "\n";
            SearchName(employeeCount, nameSr);
            system("pause");
            break;
        case(6):
            SearchByAge(Employees, employeeCount);
            system("pause");
            break;
        case(7):
            SearchByLetter(Employees, employeeCount);
            system("pause");
            break;
        case(8):
            cout << "До свидания" << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
