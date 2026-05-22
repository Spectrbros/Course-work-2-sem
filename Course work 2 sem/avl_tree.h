#pragma once
#include <string>
#include <fstream>
using namespace std;

struct Node {
	int value;
	int height;
	Node* left;
	Node* right;

	Node(int data) : value(data), height(0), left(nullptr), right(nullptr) {}
};

struct Trunk {
	Trunk* prev;
	string str;
	Trunk(Trunk* prev, string str) : prev(prev), str(str) {}
};

class AvlTree {
private:
	Node* root;

	void show_trunk(Trunk* p, string mode, ofstream& file);
	void print_tree(Node* root, Trunk* prev, bool is_right, string mode, ofstream& file);

	void clear(Node* root);
	Node* search_element(int value, Node* root);

	int height(Node* p);
	int bfactor(Node* p);
	void fix_height(Node* p);
	Node* rotate_right(Node* p);
	Node* rotate_left(Node* q);
	Node* balance(Node* p);
	Node* insert_node(Node* p, int value);

public:
	AvlTree();
	~AvlTree();

	void print(string mode, ofstream& file);
	int insert(int value);
	int remove(int value);
	int search(int value);

	bool is_created();
	void clear_all();
};