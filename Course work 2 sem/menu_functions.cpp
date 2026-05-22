#include "service_functions.h"
#include "menu_functions.h"
#include "avl_tree.h"
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;
using namespace chrono;

int tree_create_random(AvlTree& tree, int num_elements) {
    srand(time(NULL));
    auto start = steady_clock::now();
    
    for (int i = 0; i < num_elements; i++) {
        tree.insert(rand() % 199 - 99);
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    
    return result.count();
}

int tree_create_hand(AvlTree& tree,vector<int>& elements) {
    auto start = steady_clock::now();

    for (int i = 0; i < elements.size(); i++) {
        tree.insert(elements[i]);
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    return result.count();
}

int tree_insert_element(AvlTree& tree, int value, int& balance_time) {
    auto start = steady_clock::now();

    tree.insert(value);

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    
    balance_time = tree.get_balance_time();
    return result.count();
}

int tree_remove_element(AvlTree& tree, int value, int& balance_time) {
    auto start = steady_clock::now();

    tree.remove(value);

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    balance_time = tree.get_balance_time();
    return result.count();
}

int tree_search_element(AvlTree& tree, int value) {
    auto start = steady_clock::now();

    Node* temp = tree.search(value);

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    if (temp) {
        cout << GREEN << "Число " << RED << value << GREEN << " найдено в дереве!" << RESET << endl;
    }
    else {
        cout << RED << "Число не найдено в дереве!" << RESET << endl;
    }

    return result.count();
}

int tree_check_balance(AvlTree& tree) {
    auto start = steady_clock::now();

    bool temp = tree.is_balance();

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    if (temp) {
        cout << GREEN << "Дерево сбалансировано!" << RESET << endl;
    }
    else {
        cout << RED << "Дерево не сбалансировано!" << RESET << endl;
    }

    return result.count();
}

bool generate_tasks_main(int num_var) {
    ofstream file_task("output_task.txt");
    ofstream file_key("output_key.txt");
    ofstream file_ans("output_ans.txt");

    if (!file_task.is_open() || !file_key.is_open() || !file_ans.is_open()) {
        return 0;
    }

    srand(time(NULL));

    for (int var = 1; var <= num_var; ++var) {
        int num_elements = 5 + rand() % 4;
        vector<int> elements;

        while (elements.size() < num_elements) {
            int num = rand() % 199 - 99;
            bool duplicate = false;

            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] == num) {
                    duplicate = true;
                }
            }

            if (!duplicate) {
                elements.push_back(num);
            }
        }

        int num_remove = elements[rand() % elements.size()];
        int num_insert = rand() % 199 - 99;

        while (true) {
            bool duplicate = false;
            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] == num_insert) {
                    duplicate = true;
                }
            }

            if (!duplicate && num_insert != num_remove) 
                break;

            num_insert = rand() % 199 - 99;
        }

        generate_task_file(var, elements, num_remove, num_insert, file_task);
        generate_key_file(var, elements, num_remove, num_insert, file_key);
        generate_ans_file(var, elements, num_remove, num_insert, file_ans);
    }

    file_task.close();
    file_key.close();
    file_ans.close();

    return 1;
}

void generate_task_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file) {
    file << "----------------------------------------\n";
    file << "=== Вариант " << var << " ===\n\n";
    file << "1. Постройте АВЛ-дерево из элементов: [";
    for (int i = 0; i < elements.size(); ++i) {
        file << elements[i] << (i == elements.size() - 1 ? "" : ", ");
    }
    file << "]\n";
    file << "2. Удалите элемент: " << num_remove << "\n";
    file << "3. Вставьте элемент: " << num_insert << "\n";
    file << "----------------------------------------\n\n";
}

void generate_key_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file) {
    AvlTree final_tree;
    for (int i = 0; i < elements.size(); i++) {
        final_tree.insert(elements[i]);
    }
    final_tree.remove(num_remove);
    final_tree.insert(num_insert);

    file << "----------------------------------------\n";
    file << "=== Вариант " << var << " ===\n"; 
    file << "(Финальный вид дерева):\n\n";
    final_tree.print("file", file);
    file << "\n----------------------------------------\n\n";
}

void generate_ans_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file) {
    AvlTree temp_tree;

    file << "----------------------------------------\n";
    file << "=== Вариант " << var << " ===\n\n";
    file << "Шаг 1. Строим дерево из массива:\n\n";
    for (int i = 0; i < elements.size(); i++) {
        temp_tree.insert(elements[i]);
    }
    temp_tree.print("file", file);
    file << "\n";

    file << "Шаг 2. Удаляем элемент " << num_remove << ":\n\n";
    temp_tree.remove(num_remove);
    temp_tree.print("file", file);
    file << "\n";

    file << "Шаг 3. Вставляем элемент " << num_insert << ":\n\n";
    temp_tree.insert(num_insert);
    temp_tree.print("file", file);
    file << "\n----------------------------------------\n\n";
}