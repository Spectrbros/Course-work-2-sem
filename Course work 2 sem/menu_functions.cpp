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
        //tree.add(rand() % 199 - 99)
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    
    return result.count();
}

int tree_create_hand(AvlTree& tree,vector<int>& elements) {
    srand(time(NULL));
    auto start = steady_clock::now();

    for (int i = 0; i < elements.size(); i++) {
        //tree.add(elements[i])
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    return result.count();
}

int tree_insert_element(AvlTree& tree, int value) {

}

int tree_delete_element(AvlTree& tree, int value) {

}

int tree_search_element(AvlTree& tree, int value) {

}