#pragma once
#include<deque>
#include<iostream>
#include<my_menu.h>
#include <conio.h>

using path_t = std::deque<int>;

extern const char operator_list[];

class threaded_tree;
struct bin_tree_node;
struct my_tree_node;
struct threaded_node;

void erase_node(bin_tree_node* node);
void erase_node(my_tree_node* node);
void erase_node(threaded_node* node);
bool is_val_in_vars(int val, std::deque<int> vars);
threaded_node* thrd_from_bin(bin_tree_node* input, threaded_node* prev, threaded_node* next);

class tree_exception : public std::logic_error
{
public:
	explicit tree_exception(const char* message) :logic_error(message) {}
};

struct my_tree_node
{
	int val = NULL;
	my_tree_node* father = nullptr;
	std::deque<my_tree_node*> sons;
};

class my_tree
{
private:

	my_tree_node* root = nullptr;

	my_tree_node* node_at_val(int val);

public:

	int val_at_path(path_t path);

	path_t path_of_val(int val);

	void append(path_t path, int val);			//	Path to father element

	void show();

	my_tree* remove(path_t path);

	bool is_empty();

	~my_tree();
};

struct bin_tree_node
{
	int val;
	bin_tree_node* l_son = nullptr;
	bin_tree_node* r_son = nullptr;
	bin_tree_node* father = nullptr;
};

class my_bin_tree
{
private:

	bin_tree_node* root = nullptr;
	std::deque<int> vars;
	void simpl(std::deque<int> vars);

public:
	friend class threaded_tree;
	friend void demo_mode();
	
	void push(int val);

	void show();

	void append(path_t path, int val);			//	Path to father element

	void expr_show();

	void simplify();

	bool is_empty();

	void get_expr();

	bool append_expr(int val, std::deque<int>& vars);

	void solve();

	~my_bin_tree();
};

struct threaded_node :public bin_tree_node
{
	int val;
	threaded_node* l_son = nullptr;
	threaded_node* r_son = nullptr;
	threaded_node* father = nullptr;;
	bool is_r_son = false;
	bool is_l_son = false;
};

class threaded_tree
{
private:
	threaded_node* root = nullptr;

	void print_node(int& i);

public:
	threaded_tree();

	explicit threaded_tree(my_bin_tree& input);

	void show();

	~threaded_tree();
};