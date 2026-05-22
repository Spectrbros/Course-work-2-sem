#include "service_functions.h"
#include "menu_functions.h"
#include <chrono>
#include <vector>
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