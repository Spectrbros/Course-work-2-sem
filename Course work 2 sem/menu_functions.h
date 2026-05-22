#pragma once
#include <vector>
#include "avl_tree.h"
using namespace std;

int tree_create_random(AvlTree& tree, int num);
int tree_create_hand(AvlTree& tree, vector<int>& elements);
int tree_insert_element(AvlTree& tree, int value, int& balance_time);
int tree_remove_element(AvlTree& tree, int value, int& balance_time);
int tree_search_element(AvlTree& tree, int value);
int tree_check_balance(AvlTree& tree);
bool generate_tasks_main(int num_var);
void generate_task_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file);
void generate_key_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file);
void generate_ans_file(int var, vector<int>& elements, int num_remove, int num_insert, ofstream& file);