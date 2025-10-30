#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Задание 1.
// Класс имитирует работу обычного типа double.
// Есть методы обнуления, инициализации, вывода и сложения.
class Double {
    double value;
public:
    Double() : value(0.0) {}
    void setZero() { value = 0.0; }
    void set(double x) { value = x; }
    void display() const { cout << "Значение: " << value << endl; }
    void add(const Double& a, const Double& b) { value = a.value + b.value; }
};

// Задание 2.
class Employee {
    int number;
    float salary;
public:
    void getData() {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад: ";
        cin >> salary;
    }
    void putData() const {
        cout << "Номер: " << number << "\tОклад: " << salary << " руб.\n";
    }
};

// Задание 3.
class Date {
    int month, day, year;
public:
    void getDate() {
        char ch;
        cout << "Введите дату (мм/дд/гг): ";
        cin >> month >> ch >> day >> ch >> year;
    }
    void showDate() const {
        cout << setfill('0') << setw(2) << month << "/"
            << setw(2) << day << "/"
            << setw(2) << year << endl;
    }
};

// Задание 4.
// Класс для хранения времени. Пользователь вводит данные сам.
class Time {
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void getTime() {
        char ch;
        cout << "Введите время (чч:мм:сс): ";
        cin >> hours >> ch >> minutes >> ch >> seconds;
    }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    void sum(const Time& t1, const Time& t2) {
        long total = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds)
            + (t2.hours * 3600 + t2.minutes * 60 + t2.seconds);
        hours = (total / 3600) % 24;
        minutes = (total % 3600) / 60;
        seconds = total % 60;
    }
};

// Задание 5.
enum etype { laborer, secretary, manager, accountant, executive, researcher };

class FullEmployee {
    int number;
    float salary;
    Date hireDate;
    etype status;
public:
    void getEmploy() {
        char ch;
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад: ";
        cin >> salary;
        hireDate.getDate();
        cout << "Введите первую букву должности (l/s/m/a/e/r): ";
        cin >> ch;
        switch (ch) {
        case 'l': status = laborer; break;
        case 's': status = secretary; break;
        case 'm': status = manager; break;
        case 'a': status = accountant; break;
        case 'e': status = executive; break;
        case 'r': status = researcher; break;
        default: status = laborer;
        }
    }

    void putEmploy() const {
        cout << "\nНомер: " << number
            << "\tОклад: " << salary << "\tДата приёма: ";
        hireDate.showDate();
        cout << "Должность: ";
        switch (status) {
        case laborer: cout << "laborer"; break;
        case secretary: cout << "secretary"; break;
        case manager: cout << "manager"; break;
        case accountant: cout << "accountant"; break;
        case executive: cout << "executive"; break;
        case researcher: cout << "researcher"; break;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Menu menu;
    int choice;

    do {
        choice = menu.show();
        system("cls");

        switch (choice) {

        case 1: {
            cout << "ЗАДАНИЕ 1 — Класс Double (ввод пользователя)\n\n";
            Double a, b, c;

            double val1, val2;
            cout << "Введите первое число: ";
            cin >> val1;
            cout << "Введите второе число: ";
            cin >> val2;

            a.set(val1);
            b.set(val2);
            c.add(a, b);

            cout << "\nРезультат сложения: ";
            c.display();
            break;
        }

        case 2: {
            cout << "ЗАДАНИЕ 2 — Класс Employee\n\n";
            Employee e[3];
            for (int i = 0; i < 3; i++) {
                cout << "\nСотрудник #" << i + 1 << ":\n";
                e[i].getData();
            }
            cout << "\nСписок сотрудников:\n";
            for (int i = 0; i < 3; i++) e[i].putData();
            break;
        }

        case 3: {
            cout << "ЗАДАНИЕ 3 — Класс Date\n\n";
            Date d;
            d.getDate();
            cout << "Введённая дата: ";
            d.showDate();
            break;
        }

        case 4: {
            cout << "ЗАДАНИЕ 4 — Класс Time (ввод пользователя)\n\n";
            Time t1, t2, t3;
            cout << "Введите первое время:\n";
            t1.getTime();
            cout << "Введите второе время:\n";
            t2.getTime();

            t3.sum(t1, t2);
            cout << "\nРезультат сложения времени: ";
            t3.display();
            break;
        }

        case 5: {
            cout << "ЗАДАНИЕ 5 — Расширенный Employee\n\n";
            FullEmployee e[3];
            for (int i = 0; i < 3; i++) {
                cout << "\nСотрудник #" << i + 1 << ":\n";
                e[i].getEmploy();
            }
            cout << "\nИнформация о сотрудниках:\n";
            for (int i = 0; i < 3; i++) e[i].putEmploy();
            break;
        }

        case 0:
            cout << "Выход из программы...\n";
            break;

        default:
            cout << "Неверный выбор!\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter, чтобы вернуться в меню...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls");
        }

    } while (choice != 0);

    return 0;
}