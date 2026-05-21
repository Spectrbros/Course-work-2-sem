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

    //func

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