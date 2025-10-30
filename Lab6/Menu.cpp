#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::show() {
    cout << "==============================\n";
    cout << "        ÌÅÍÞ ËÀÁÎÐÀÒÎÐÍÎÉ 6    \n";
    cout << "==============================\n";
    cout << "1. Êëàññ Double\n";
    cout << "2. Êëàññ Employee\n";
    cout << "3. Êëàññ Date\n";
    cout << "4. Êëàññ Time\n";
    cout << "5. Ðàñøèðåííûé Employee + Date + Enum\n";
    cout << "0. Âûõîä\n";
    cout << "------------------------------\n";
    cout << "Ââåäèòå íîìåð çàäàíèÿ: ";

    int choice;
    cin >> choice;
    return choice;
}
