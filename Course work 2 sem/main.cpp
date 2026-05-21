#include "service_functions.h"
#include "menu_output.h"
#include "avl_tree.h"
using namespace std;

// Главная функция
int main() {
    setlocale(0, "");
    AvlTree tree;
    bool is_should_exit = 0;
    while (!is_should_exit) {
        print_menu(tree, is_should_exit);
    }
    return 0;
}