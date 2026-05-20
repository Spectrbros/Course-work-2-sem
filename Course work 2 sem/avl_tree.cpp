#include "avl_tree.h"
using namespace std;

// Работа с деревом
struct Node {	
	int value;
	int height;
	Node* left;
	Node* right;

	Node(int data) : value(data), height(0), left(nullptr), right(nullptr){}
};

class AvlTree {
	private:
		Node* root;

	public:
		AvlTree() : root(nullptr) {};

		~AvlTree() {
			//clear(root);
		}
};