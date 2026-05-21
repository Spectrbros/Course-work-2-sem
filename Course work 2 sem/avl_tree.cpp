#include "avl_tree.h"
#include <chrono>
using namespace std;
using namespace chrono;

//Работа с деревом

//private
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

void print() {

}

int insert(int value) {
    auto start = steady_clock::now();

    //func

    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    return result.count();
}

int remove(int value) {
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