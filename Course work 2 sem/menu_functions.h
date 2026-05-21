#pragma once
#include <vector>
#include "avl_tree.h"

int tree_create_random(AvlTree& tree, int num);
int tree_create_hand(AvlTree& tree, std::vector<int>& elements);
int tree_insert_element(AvlTree& tree, int value);
int tree_delete_element(AvlTree& tree, int value);
int tree_search_element(AvlTree& tree, int value);