#include "service_functions.h"
#include <chrono>
using namespace std;
using namespace chrono;

// Служебные функции
void separation() {
    cout << "\n";
}

void stream_clear() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void waiting() {
    separation();
    separation();
    cout << RED << "Нажмите Enter для продолжения..." << RESET << endl;
    cin.get();
}

void error_detention() {
    stream_clear();
    separation();
    separation();
    cout << RED << "Нажмите Enter для продолжения..." << RESET << endl;
    cin.get();
}

void clear_screen() {
    system("cls");
}