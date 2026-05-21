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
	Node* search_element(int value, Node* root);

public:
	AvlTree();
	~AvlTree();

	void print();
	void insert(int value);
	void remove(int value);
	int search(int value);

	bool is_created();
	void clear_all();
};