#pragma once
#include <iostream>
#include <iomanip>
#include <string>  

// Функции меню
void print_menu(AvlTree& tree);
void lab_page();
void command_choice(AvlTree& tree);
void menu_commands(int choice, AvlTree& tree);
void create_tree_menu();
void output_tree_menu();
void tree_operations_menu();
void tree_balance_menu();
void tree_tasks_menu();