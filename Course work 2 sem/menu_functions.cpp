#include "service_functions.h"
#include "menu_functions.h"
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;



int tree_create_random(int num) {
    srand(time(NULL));
    auto start = steady_clock::now();
    
    for (int i = 0; i < num; i++) {
        //tree.add(rand() % 199 - 99)
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    
    return result.count();
}

int tree_create_hand(vector<int>& elements) {
    srand(time(NULL));
    auto start = steady_clock::now();

    for (int i = 0; i < elements.size(); i++) {
        //tree.add(elements[i])
    }

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    return result.count();
}