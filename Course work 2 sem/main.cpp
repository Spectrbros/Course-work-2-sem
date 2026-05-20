#include "service_functions.h"
#include "menu_output.h"
#include "avl_tree.h"
using namespace std;

// Главная функция
int main() {
    setlocale(0, "");
    AvlTree tree;
    while (true) {
        print_menu(tree);
    }
    return 0;
}