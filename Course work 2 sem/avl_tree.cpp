#include "avl_tree.h"
using namespace std;

// Работа с деревом

//private
void AvlTree::clear(Node* root) {
      if(root != nullptr)	    	       
      {					
          clear(root->left);
          clear(root->right);
          delete root;			
      }
}

//public
AvlTree::AvlTree() : root(nullptr) {}

AvlTree::~AvlTree() {
	clear(root);
}

bool AvlTree::is_created() {
    return root != nullptr;
}

void AvlTree::clear_all() {
    clear(root);
    root = nullptr;
}