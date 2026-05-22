#include "avl_tree.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

//Работа с деревом

//private

void AvlTree::show_trunk(Trunk* p, string mode, ofstream& file) {
    if (p == nullptr) return;
    show_trunk(p->prev, mode, file);

    if (mode == "console") {
        cout << p->str;
    }
    else {
        if (mode == "file") {
            file << p->str;
        }
    }
}

void AvlTree::print_tree(Node* root, Trunk* prev, bool is_right, string mode, ofstream& file) {
    if (root == nullptr) return;

    string prev_str = "    ";
    Trunk* tmp = new Trunk(prev, prev_str);

    print_tree(root->right, tmp, true, mode, file);

    if (!prev) {
        tmp->str = "-->";
    }
    else {
        if (is_right) {
            tmp->str = ".-->";
            prev_str = "   |";
        }
        else {
            tmp->str = "`-->";
            prev->str = prev_str;
        }
    }

    show_trunk(tmp, mode, file);

    if (mode == "console") {
        cout << root->value << endl;
    }
    else {
        if (mode == "file") {
            file << root->value << endl;
        }
    }

    if (prev) {
        prev->str = prev_str;
    }
    tmp->str = "   |";

    print_tree(root->left, tmp, false, mode, file);

    delete tmp;
}

void AvlTree::clear(Node* root) {
      if(root != nullptr)	    	       
      {					
          clear(root->left);
          clear(root->right);
          delete root;			
      }
}

Node* AvlTree::search_element(int value, Node* root) {
    if (root == nullptr)
        return nullptr;

    if (value == root->value)
        return root;
    if (value < root->value)
        return search_element(value, root->left);
    else
        return search_element(value, root->right);
}

Node* AvlTree::remove_node(Node* p, int value) {
    if (p == nullptr) {
        return nullptr;
    }

    if (value < p->value) {
        p->left = remove_node(p->left, value);
        return balance(p);
    }

    if (value > p->value) {
        p->right = remove_node(p->right, value);
        return balance(p);
    }

    Node* left_child = p->left;
    Node* right_child = p->right;

    if (left_child == nullptr) {
        delete p;
        return right_child;
    }

    if (right_child == nullptr) {
        delete p;
        return left_child;
    }

    Node* max_left = left_child;
    while (max_left->right != nullptr) {
        max_left = max_left->right;
    }

    p->value = max_left->value;

    p->left = remove_node(p->left, max_left->value);

    return balance(p);
}

int AvlTree::height(Node* p) {
    if (p) 
        return p->height;
    else
        return 0;
}

int AvlTree::bfactor(Node* p) {
    return height(p->right) - height(p->left);
}

void AvlTree::fix_height(Node* p) {
    int height_left_child = height(p->left);
    int height_right_child = height(p->right);
    p->height = (height_left_child > height_right_child ? height_left_child : height_right_child) + 1;
}

Node* AvlTree::rotate_right(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fix_height(p);
    fix_height(q);
    return q;
}

Node* AvlTree::rotate_left(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fix_height(q);
    fix_height(p);
    return p;
}

Node* AvlTree::balance(Node* p) {
    auto start = steady_clock::now();

    fix_height(p);

    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0)
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }

    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0)
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }

    auto end = steady_clock::now();
    balance_time += duration_cast<nanoseconds>(end - start).count();

    return p;
}

Node* AvlTree::insert_node(Node* p, int value) {
    if (!p) return new Node(value);

    if (value == p->value) return p;

    if (value < p->value)
        p->left = insert_node(p->left, value);
    else
        p->right = insert_node(p->right, value);

    return balance(p);
}

bool AvlTree::check_balance(Node* p) {
    if (p == nullptr) return true;

    int factor = bfactor(p);
    if (factor < -1 || factor > 1) {
        return false; 
    }

    return check_balance(p->left) && check_balance(p->right);
}

//public
AvlTree::AvlTree() : root(nullptr), balance_time(0) {}

AvlTree::~AvlTree() {
	clear(root);
}

void AvlTree::print(string mode, ofstream& file) {
    print_tree(root, nullptr, false, mode, file);
}

void AvlTree::insert(int value) {
    reset_balance_time();
    root = insert_node(root, value);
}

void AvlTree::remove(int value) {
    reset_balance_time();
    root = remove_node(root, value);
}

Node* AvlTree::search(int value) {
    return search_element(value, root);
}

bool AvlTree::is_balance() {
    return check_balance(root);
}

int AvlTree::get_balance_time() {
    return balance_time;
}

void AvlTree::reset_balance_time() {
    balance_time = 0;
}

bool AvlTree::is_created() {
    return root != nullptr;
}

void AvlTree::clear_all() {
    clear(root);
    root = nullptr;
}