// var2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100; // Максимальное количество сотрудников
int employeeCount = 0; // Текущее количество сотрудников
struct Employee {
    string name;
    int age;
    string position;
};
Employee employees[MAX_EMPLOYEES]; // Массив для хранения сотрудников

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Cannot add more employees!" << endl;
        return;
    }
    Employee employee;
    cout << "Enter name: ";
    getline(cin, employee.name);
    cout << "Enter age: ";
    cin >> employee.age;
    cin.ignore();
    cout << "Enter position: ";
    getline(cin, employee.position);
    employees[employeeCount] = employee;
    employeeCount++;
    cout << "Employee added!" << endl;
}

void editEmployee() {
    int index;
    cout << "Enter index of employee to edit: ";
    cin >> index;
    cin.ignore();
    if (index < 0 || index >= employeeCount) {
        cout << "Invalid index!" << endl;
        return;
    }
    Employee& employee = employees[index];
    cout << "Enter new name: ";
    getline(cin, employee.name);
    cout << "Enter new age: ";
    cin >> employee.age;
    cin.ignore();
    cout << "Enter new position: ";
    getline(cin, employee.position);
    cout << "Employee edited!" << endl;
}

void deleteEmployee() {
    int index;
    cout << "Enter index of employee to delete: ";
    cin >> index;
    if (index < 0 || index >= employeeCount) {
        cout << "Invalid index!" << endl;
        return;
    }
    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employeeCount--;
    cout << "Employee deleted!" << endl;
}

int main() {
    int choice;
    do {
        cout << "1. Add employee" << endl;
        cout << "2. Edit employee" << endl;
        cout << "3. Delete employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            editEmployee();
            break;
        case 3:
            deleteEmployee();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
