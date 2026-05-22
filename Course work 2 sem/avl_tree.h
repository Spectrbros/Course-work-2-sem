#pragma once
#include <string>
#include <fstream>
using namespace std;

struct Node {
	int value;
	int height;
	Node* left;
	Node* right;

	Node(int data) : value(data), height(1), left(nullptr), right(nullptr) {}
};

struct Trunk {
	Trunk* prev;
	string str;
	Trunk(Trunk* prev, string str) : prev(prev), str(str) {}
};

class AvlTree {
private:
	Node* root;       // корень дерева
	int balance_time; // замер времени балансировки для операций: вставка и удаление

	int height(Node* p);
	int bfactor(Node* p);
	void fix_height(Node* p);
	Node* rotate_right(Node* p);
	Node* rotate_left(Node* q);
	Node* balance(Node* p);

	Node* insert_node(Node* p, int value);
	Node* remove_node(Node* p, int value);
	Node* search_node(int value, Node* root);

	void show_trunk(Trunk* p, string mode, ofstream& file);
	void print_tree(Node* root, Trunk* prev, bool is_right, string mode, ofstream& file);
	bool check_balance(Node* p);

	void clear(Node* root);

public:
	AvlTree();
	~AvlTree();

	void insert(int value);
	void remove(int value);
	Node* search(int value);
	void print(string mode, ofstream& file);

	bool is_created();
	bool is_balance();

	int get_balance_time();
	void reset_balance_time();

	void clear_all();
};