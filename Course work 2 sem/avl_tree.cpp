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
    else if (mode == "file") {
        file << p->str;
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
    else if (is_right) {
        tmp->str = ".-->";
        prev_str = "   |";
    }
    else {
        tmp->str = "`-->";
        prev->str = prev_str;
    }

    show_trunk(tmp, mode, file);

    if (mode == "console") {
        cout << root->value << endl;
    }
    else if (mode == "file") {
        file << root->value << endl;
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
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
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
    return p;
}

Node* AvlTree::insert_node(Node* p, int value) {
    if (!p) return new Node(value);

    if (value < p->value)
        p->left = insert_node(p->left, value);
    else
        p->right = insert_node(p->right, value);

    return balance(p);
}

//public
AvlTree::AvlTree() : root(nullptr) {}

AvlTree::~AvlTree() {
	clear(root);
}

void AvlTree::print(string mode, ofstream& file) {
    print_tree(root, nullptr, false, mode, file);
}

int AvlTree::insert(int value) {
    auto start = steady_clock::now();
        
    root = insert_node(root, value);

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    return result.count();
}

int AvlTree::remove(int value) {
    auto start = steady_clock::now();

    //func

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    return result.count();
}

int AvlTree::search(int value) {
    auto start = steady_clock::now();

    search_element(value, root);

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    return result.count();
}

bool AvlTree::is_created() {
    return root != nullptr;
}

void AvlTree::clear_all() {
    clear(root);
    root = nullptr;
}