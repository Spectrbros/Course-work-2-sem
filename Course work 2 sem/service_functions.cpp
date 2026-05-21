#include "service_functions.h"
#include <chrono>
using namespace std;
using namespace chrono;

// Служебные функции
void separation() {
    cout << "\n";
}

void clear_stream() {
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
    clear_stream();
    separation();
    separation();
    cout << RED << "Нажмите Enter для продолжения..." << RESET << endl;
    cin.get();
}

void clear_screen() {
    system("cls");
}