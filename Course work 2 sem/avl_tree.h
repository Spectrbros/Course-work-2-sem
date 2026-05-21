#pragma once
struct Node {
	int value;
	int height;
	Node* left;
	Node* right;

	Node(int data) : value(data), height(0), left(nullptr), right(nullptr) {}
};

class AvlTree {
private:
	Node* root;

	void clear(Node* root);
public:
	AvlTree();
	
	void print();
	void insert(int value);
	void remove(int value);
	void search(int value);
	void check_balance();
	bool is_created();
	void clear_all();

	~AvlTree();
};