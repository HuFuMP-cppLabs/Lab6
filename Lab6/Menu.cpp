#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::show() {
    cout << "==============================\n";
    cout << "        ���� ������������ 6    \n";
    cout << "==============================\n";
    cout << "1. ����� Double\n";
    cout << "2. ����� Employee\n";
    cout << "3. ����� Date\n";
    cout << "4. ����� Time\n";
    cout << "5. ����������� Employee + Date + Enum\n";
    cout << "0. �����\n";
    cout << "------------------------------\n";
    cout << "������� ����� �������: ";

    int choice;
    cin >> choice;
    return choice;
}
