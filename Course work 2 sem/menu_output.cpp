#include "service_functions.h"
#include "menu_functions.h"
#include "menu_output.h"
#include "avl_tree.h"
#include <vector>
using namespace std;

// Вывод меню
void print_menu(AvlTree& tree) {
    lab_page();
    command_choice(tree);
    clear_screen();
}

void lab_page() {
    cout << "|=========================================================|" << endl;
    cout << "|              " << BLUE << "Курсовая работа. АВЛ-дерево." << RESET << "               |" << endl;
    cout << "|=========================================================|" << endl;
    cout << "| " << GREEN << "1) Сформировать дерево" << RESET << "                                  |" << endl;
    cout << "| " << GREEN << "2) Вывод дерева" << RESET << "                                         |" << endl;
    cout << "| " << GREEN << "3) Операции над деревом" << RESET << "            |" << endl;
    cout << "| " << GREEN << "4) Сгенерировать задания" << RESET << "                                |" << endl;
    cout << "|                                                         |" << endl;
    cout << "| " << RED << "0) Выход и очистка памяти" << RESET << "                               |" << endl;
    cout << "|=========================================================|" << endl;
    cout << "|              " << BLUE << "Курсовая работа. АВЛ-дерево." << RESET << "               |" << endl;
    cout << "|=========================================================|" << endl;
    cout << endl;
}

void command_choice(AvlTree& tree) {
    cout << BLUE << "Введите номер команды: " << RESET;
    int user_choice;
    if (cin >> user_choice) {
        stream_clear();
        menu_commands(user_choice, tree);
    }
    else {
        cout << RED << "Ошибка! Введите номер команды от 0 до 5!\n" << RESET << endl;
        error_detention();
    }
}

void menu_commands(int choice, AvlTree& tree) {
    clear_screen();
    switch (choice) {
    case 0:
        cout << GREEN << "Память очищена, программа завершена!" << RESET << endl;
        exit(0);
    case 1:
        create_tree_menu(tree);
        waiting();
        break;
    case 2:
        output_tree_menu();
        waiting();
        break;
    case 3:
        waiting();
        break;
    case 4:
        waiting();
        break;
    default:
        cout << RED << "Ошибка! Введите номер команды от 0 до 5!\n" << RESET << endl;
        waiting();
        break;
    }
}

void create_tree_menu(AvlTree& tree) {
    //if (tree.is_fill) {
    //    tree.clear();
    //}
    while (true) {
        clear_screen();
        cout << BLUE << "Сформировать АВЛ-дерево и заполнить:" << RESET << endl;
        cout << GREEN << "1) Случайными числами от -99 до 99" << RESET << endl;
        cout << GREEN << "2) Вручную" << RESET << endl;
        cout << BLUE << "Выбор:" << RESET;
        int user_choice;
        if (cin >> user_choice && (user_choice == 1 || user_choice == 2)) {
            stream_clear();
            switch (user_choice) {
                case 1: {
                    while (true) {
                        clear_screen();
                        int num_elements = 0;
                        cout << BLUE << "Введите количество элементов: " << RESET;
                        if (cin >> num_elements && num_elements > 0) {
                            int tree_time_create = tree_create_random(num_elements);
                            stream_clear();
                            cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                            cout << GREEN << "Общее время балансировки дерева: " << RED << " нс" << RESET;
                        }
                        else {
                            clear_screen();
                            cout << RED << "Введите число больше 0!\n" << RESET << endl;
                            error_detention();
                        }
                    }
                    break;
                }
                case 2: {
                    clear_screen();
                    vector<int> elements;
                    cout << BLUE << "Введите числа (введите любую букву, чтобы закончить): " << RESET;
                    int temp = 0;
                    while (cin >> temp) {
                        elements.push_back(temp);
                    }
                    int tree_time_create = tree_create_hand(elements);
                    stream_clear();
                    cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                    cout << GREEN << "Общее время балансировки дерева: " << RED << " нс" << RESET;
                    break;
                }
            }
        }
        else {
            clear_screen();
            cout << RED << "Ошибка! Введите номер команды от 1 до 2!\n" << RESET << endl;
            error_detention();
        }
    }
}

void output_tree_menu() {
    //if (!tree.is_fill) {
    cout << RED << "АВЛ-дерево ещё не создано!" << RESET;
    waiting();
    //}
    clear_screen();
    cout << BLUE << "Текущее АВД-дерево:" << RESET << endl;
    //tree.output()
}

void tree_operations_menu() {
    while (true) {
        clear_screen();
        cout << BLUE << "Выберите действие над АВЛ-деревом:" << RESET << endl;
        cout << GREEN << "1) Вставка элемента" << RESET << endl;
        cout << GREEN << "2) Удаление элемента" << RESET << endl;
        cout << GREEN << "3) Получение элемента" << RESET << endl;
        cout << BLUE << "Выбор:" << RESET;
        int user_choice;
        if (cin >> user_choice && (user_choice == 1 || user_choice == 2 || user_choice == 3)) {
            stream_clear();
            switch (user_choice) {
            case 1: {
                while (true) {
                    clear_screen();
                    int num_elements = 0;
                    cout << BLUE << "Введите количество элементов: " << RESET;
                    if (cin >> num_elements && num_elements > 0) {
                        int tree_time_create = tree_create_random(num_elements);
                        stream_clear();
                        cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                        cout << GREEN << "Общее время балансировки дерева: " << RED << " нс" << RESET;
                    }
                    else {
                        clear_screen();
                        cout << RED << "Введите число больше 0!\n" << RESET << endl;
                        error_detention();
                    }
                }
                break;
            }
            case 2: {
                clear_screen();
                vector<int> elements;
                cout << BLUE << "Введите числа (введите любую букву, чтобы закончить): " << RESET;
                int temp = 0;
                while (cin >> temp) {
                    elements.push_back(temp);
                }
                int tree_time_create = tree_create_hand(elements);
                stream_clear();
                cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                cout << GREEN << "Общее время балансировки дерева: " << RED << " нс" << RESET;
                break;
            }
            }
        }
        else {
            clear_screen();
            cout << RED << "Ошибка! Введите номер команды от 1 до 3!\n" << RESET << endl;
            error_detention();
        }
    }
}
void tree_tasks_menu();