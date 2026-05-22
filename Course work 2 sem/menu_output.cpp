#include "service_functions.h"
#include "menu_functions.h"
#include "menu_output.h"
#include "avl_tree.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Вывод меню
void print_menu(AvlTree& tree, bool& is_should_exit) {
    lab_page();
    command_choice(tree, is_should_exit);
    clear_screen();
}

void lab_page() {
    cout << "|==================================|" << endl;
    cout << "|   " << BLUE << "Курсовая работа. АВЛ-дерево." << RESET << "   |" << endl;
    cout << "|==================================|" << endl;
    cout << "| " << GREEN << "1) Сформировать дерево" << RESET << "           |" << endl;
    cout << "| " << GREEN << "2) Вывод дерева" << RESET << "                  |" << endl;
    cout << "| " << GREEN << "3) Операции над деревом" << RESET << "          |" << endl;
    cout << "| " << GREEN << "4) Проверка сбалансированности" << RESET << "   |" << endl;
    cout << "| " << GREEN << "5) Сгенерировать задания" << RESET << "         |" << endl;
    cout << "|                                  |" << endl;
    cout << "| " << RED << "0) Выход и очистка памяти" << RESET << "        |" << endl;
    cout << "|==================================|" << endl;
    cout << "|   " << BLUE << "Курсовая работа. АВЛ-дерево." << RESET << "   |" << endl;
    cout << "|==================================|" << endl;
    cout << endl;
}

void command_choice(AvlTree& tree, bool& is_should_exit) {
    cout << BLUE << "Введите номер команды: " << RESET;
    int user_choice;
    if (cin >> user_choice) {
        clear_stream();
        menu_commands(tree, user_choice, is_should_exit);
    }
    else {
        clear_screen();
        cout << RED << "Ошибка! Введите корректное число от 0 до 5!\n" << RESET << endl;
        error_detention();
    }
}

void menu_commands(AvlTree& tree, int choice, bool& is_should_exit) {
    clear_screen();
    switch (choice) {
    case 0:
        tree.clear_all();
        cout << GREEN << "Память очищена, программа завершена!" << RESET << endl;
        waiting();
        is_should_exit = 1;
        break;
    case 1:
        create_tree_menu(tree);
        waiting();
        break;
    case 2:
        print_tree_menu(tree);
        waiting();
        break;
    case 3:
        tree_operations_menu(tree);
        waiting();
        break;
    case 4:
        tree_balance_menu(tree);
        waiting();
        break;
    case 5:
        tree_tasks_menu(tree);
        waiting();
        break;
    default:
        cout << RED << "Ошибка! Введите номер команды от 0 до 5!\n" << RESET << endl;
        waiting();
        break;
    }
}

void create_tree_menu(AvlTree& tree) {
    if (tree.is_created()) {
        tree.clear_all();
    }
    while (true) {
        clear_screen();
        cout << BLUE << "Сформировать АВЛ-дерево и заполнить:" << RESET << endl;
        cout << GREEN << "1) Случайными числами от -99 до 99" << RESET << endl;
        cout << GREEN << "2) Вручную" << RESET << endl;
        cout << BLUE << "Выбор:" << RESET;
        int user_choice;
        if (cin >> user_choice && (user_choice == 1 || user_choice == 2)) {
            clear_stream();
            switch (user_choice) {
                case 1: {
                    while (true) {
                        clear_screen();
                        int num_elements;
                        cout << BLUE << "Введите количество элементов: " << RESET;
                        if (cin >> num_elements && num_elements > 0) {
                            clear_stream();
                            int tree_time_create = tree_create_random(tree, num_elements);
                            clear_screen();
                            cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                            return;
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
                    int temp;
                    while (cin >> temp) {
                        elements.push_back(temp);
                    }
                    clear_stream();
                    int tree_time_create = tree_create_hand(tree, elements);
                    clear_screen();
                    cout << GREEN << "АВЛ-дерево успешно сформировано за " << RED << tree_time_create << " нс" << RESET << endl;
                    return;
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

void print_tree_menu(AvlTree& tree) {
    if (!tree.is_created()) {
    cout << RED << "АВЛ-дерево ещё не создано!" << RESET;
    return;
    }
    cout << BLUE << "Текущее АВЛ-дерево:\n" << RESET << endl;
    ofstream temp;
    tree.print("console", temp);
}

void tree_operations_menu(AvlTree& tree) {
    if (!tree.is_created()) {
    cout << RED << "АВЛ-дерево ещё не создано!" << RESET;
    return;
    }
    while (true) {
        clear_screen();
        cout << BLUE << "Выберите действие над АВЛ-деревом:" << RESET << endl;
        cout << GREEN << "1) Вставка элемента" << RESET << endl;
        cout << GREEN << "2) Удаление элемента" << RESET << endl;
        cout << GREEN << "3) Получение элемента" << RESET << endl;
        cout << BLUE << "Выбор:" << RESET;
        int user_choice;
        if (cin >> user_choice && (user_choice == 1 || user_choice == 2 || user_choice == 3)) {
            clear_stream();
            switch (user_choice) {
            case 1: {
                while (true) {
                    clear_screen();
                    cout << RED << "АВЛ-дерево до изменения:\n" << RESET << endl;
                    ofstream temp;
                    tree.print("console", temp);
                    cout << endl;
                    cout << BLUE << "Введите число для вставки: " << RESET;
                    int value;
                    if (cin >> value) {
                        clear_stream();
                        clear_screen();
                        int balance_time = 0;
                        int tree_time_operation = tree_insert_element(tree, value, balance_time);
                        cout << RED << "АВЛ-дерево после изменения:\n" << RESET << endl;
                        ofstream temp;
                        tree.print("console", temp);
                        cout << endl;
                        cout << GREEN << "Время вставки элемента: " << RED << tree_time_operation << " нс" << RESET << endl;
                        cout << GREEN << "Время балансировки дерева: " << RED << balance_time << " нс" << RESET;
                        return;
                    }
                    else {
                        clear_screen();
                        cout << RED << "Введите корректное число!\n" << RESET << endl;
                        error_detention();
                    }
                }
                break;
            }
            case 2: {
                while (true) {
                    clear_screen();
                    cout << RED << "АВЛ-дерево до изменения:\n" << RESET << endl;
                    ofstream temp;
                    tree.print("console", temp);
                    cout << endl;
                    cout << BLUE << "Введите число для удаления: " << RESET;
                    int value;
                    if (cin >> value) {
                        clear_stream();
                        clear_screen();
                        if (tree.search(value)) {
                            int balance_time = 0;
                            int tree_time_operation = tree_remove_element(tree, value, balance_time);
                            cout << RED << "АВЛ-дерево после изменения:\n" << RESET << endl;
                            ofstream temp;
                            tree.print("console", temp);
                            cout << endl;
                            cout << GREEN << "Число " << RED << value << GREEN << " удалено!" << RESET << endl;
                            cout << GREEN << "Время удаления элемента: " << RED << tree_time_operation << " нс" << RESET << endl;
                            cout << GREEN << "Время балансировки дерева: " << RED << balance_time << " нс" << RESET;
                            return;
                        }
                        else {
                            clear_screen();
                            cout << RED << "Число не найдено в дереве!" << RESET << endl;
                            waiting();
                        }
                    }
                    else {
                        clear_screen();
                        cout << RED << "Введите корректное число!\n" << RESET << endl;
                        error_detention();
                    }
                }
                break;
            }
            case 3: {
                while (true) {
                    clear_screen();
                    cout << BLUE << "Введите число для поиска: " << RESET;
                    int value;
                    if (cin >> value) {
                        clear_stream();
                        clear_screen();
                        int tree_time_operation = tree_search_element(tree, value);
                        cout << GREEN << "Время поиска элемента: " << RED << tree_time_operation << " нс" << RESET << endl;
                        return;
                    }
                    else {
                        clear_screen();
                        cout << RED << "Введите корректное число!\n" << RESET << endl;
                        error_detention();
                    }
                }
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

void tree_balance_menu(AvlTree& tree) {
    if (!tree.is_created()) {
        cout << RED << "АВЛ-дерево ещё не создано!" << RESET;
        return;
    }

    int tree_time_balance = tree_check_balance(tree);
    cout << GREEN << "Время проверки на сбалансированность: " << RED << tree_time_balance << " нс" << RESET << endl;
}

void tree_tasks_menu(AvlTree& tree) {
    while (true) {
        clear_screen();
        cout << BLUE << "Генерация заданий" << RESET << endl;
        cout << GREEN << "Введите количество вариантов для генерации: " << RESET;
        int num_var;
        if (cin >> num_var && num_var > 0) {
            clear_stream();
            clear_screen();
            
            if (generate_tasks_main(num_var)) {
                cout << GREEN << "Успешно создано " << RED << num_var << GREEN << " вариантов!" << RESET << endl;
                cout << "\n" << BLUE << "Варианты и ответы находятся в следующих файлах в папке проекта:" << RESET << endl;
                cout << RED << "output_task.txt" << BLUE << "  -  варианты заданий" << RESET << endl;
                cout << RED << "output_key.txt" << BLUE << "   -  итоговые ответы" << RESET << endl;
                cout << RED << "output_ans.txt" << BLUE << "   -  расширенные ответы" << RESET << endl;
                return;
            }
            
            else {
                cout << RED << "Ошибка открытия файлов для записи!" << RESET << endl;
                waiting();
                return;
            }
        }
        else {
            clear_screen();
            cout << RED << "Ошибка! Введите число больше 0!\n" << RESET << endl;
            error_detention();
        }
    }
}