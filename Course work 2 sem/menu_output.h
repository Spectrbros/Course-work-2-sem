#pragma once
#include <iostream>
#include <iomanip>
#include <string>  
#include "avl_tree.h"

// Функции меню
void print_menu(AvlTree& tree, bool& is_should_exit);
void lab_page();
void command_choice(AvlTree& tree, bool& is_should_exit);
void menu_commands(AvlTree& tree, int choice, bool& is_should_exit);
void create_tree_menu(AvlTree& tree);
void print_tree_menu(AvlTree& tree);
void tree_operations_menu(AvlTree& tree);
void tree_tasks_menu(AvlTree& tree);