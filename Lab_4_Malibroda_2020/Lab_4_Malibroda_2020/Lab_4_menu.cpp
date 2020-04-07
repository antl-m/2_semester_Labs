#include"Lab_4.h"
#include<my_menu.h>
#include"my_tree.h"
#include<conio.h>
#include <thread>
#include <chrono>

#define SLOW std::this_thread::sleep_for(std::chrono::milliseconds(3000))
#define MEDIUM std::this_thread::sleep_for(std::chrono::milliseconds(1000))
#define FAST std::this_thread::sleep_for(std::chrono::milliseconds(500))

enum button { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };
using std::cout;
using std::endl;
using std::cin;

void start_menu()
{
	my_tree variant; //1(2, 3(7(13(18(20(24)))))
	variant.append({}, 1);
	variant.append({}, 2);
	variant.append({}, 3);
	variant.append({1}, 7);
	variant.append({1,0}, 13);
	variant.append({1,0,0}, 18);
	variant.append({1,0,0,0}, 20);
	variant.append({1,0,0,0,0}, 24);

	my_menu start({ "Interactive","Demonstration" });
	void(*start_funcs[])() = { inter_menu,demo_mode };
	int key;

	while (1) {
		clear();
		cout << "Tree of my variant: ";
		variant.show();
		cout << endl;
		start.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: start.prev(); break;
			case DOWN: start.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return start_funcs[start.cur()]();
		}
		else if (key == ESC) {
			return;
		}
	}
}

void inter_menu()
{
	my_menu inter({ "Create usual tree","Create binary tree", "Create expression" });
	void(*inter_funcs[])() = { usual_tree_creating,binary_tree_creating, expression_creating };
	int key;

	while (1) {
		clear();
		inter.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: inter.prev(); break;
			case DOWN: inter.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return inter_funcs[inter.cur()]();
		}
		else if (key == ESC) {
			return start_menu();
		}
	}
}

void demo_mode()
{
	my_menu inter({ "Create usual tree","Create binary tree", "Create expression" });
	my_menu usual({ "Add element","Delete element", "Show tree" });
	my_tree usual_tree;
	my_menu binary({ "Push element","Show tree", "Build threaded tree" });
	my_bin_tree bin_tree;
	my_menu expr({ "Input expression","Show expression", "Simplify expression", "Solve expression" });
	clear();
	inter.show();
	SLOW;
	clear();
	usual.show();
	SLOW;
	clear();
	cout << "Tree is empty\n";
	cout << "Input value: ";
	MEDIUM;
	cout << '1';
	FAST;
	cout << '0';
	FAST;
	usual_tree.append({}, 10);
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	usual.show();
	MEDIUM;
	clear();
	usual_tree.show();
	cout << endl;
	cout << "Input size of a path: ";
	MEDIUM;
	cout << '0';
	FAST;
	cout << "\nInput value: ";
	MEDIUM;
	cout << '5';
	FAST;
	usual_tree.append({}, 5);
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	usual.show();
	MEDIUM;
	usual.next();
	clear();
	usual.show();
	MEDIUM;
	clear();
	cout << "Input size of a path: ";
	MEDIUM;
	cout << '1';
	FAST;
	cout << "\nInput steps: ";
	MEDIUM;
	cout << '0';
	FAST;
	cout << "path: 0";
	my_tree* removable;
	removable = usual_tree.remove({ 0 });
	cout << "\nYour tree after deleting: ";
	usual_tree.show();
	cout << "\nDeleted part: ";
	removable->show();
	delete removable;
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	usual.show();
	usual.next();
	MEDIUM;
	clear();
	usual.show();
	MEDIUM;
	clear();
	cout << "Your tree: ";
	usual_tree.show();
	cout << endl << "Press any key";
	SLOW;
	clear();
	usual.show();
	MEDIUM;
	clear();
	inter.show();
	MEDIUM;
	clear();
	inter.next();
	inter.show();
	MEDIUM;
	clear();
	binary.show();
	MEDIUM;
	clear();
	cout << "Tree is empty\n";
	cout << "Input value: ";
	MEDIUM;
	cout << '8';
	FAST;
	bin_tree.push(8);
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	binary.show();
	MEDIUM;
	clear();
	bin_tree.show();
	cout << endl;
	cout << "Input value: ";
	MEDIUM;
	cout << '9';
	FAST;
	bin_tree.push(9);
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	binary.show();
	MEDIUM;
	clear();
	bin_tree.show();
	cout << endl;
	cout << "Input value: ";
	MEDIUM;
	cout << '7';
	FAST;
	bin_tree.push(7);
	cout << "\nPress any key to continue";
	SLOW;
	clear();
	binary.show();
	MEDIUM;
	binary.next();
	clear();
	binary.show();
	MEDIUM;
	cout << "Your tree: ";
	bin_tree.show();
	cout << endl << "Press any key";
	SLOW;
	clear();
	binary.show();
	binary.next();
	MEDIUM;
	clear();
	binary.show();
	MEDIUM;
	clear();
	threaded_tree temp(bin_tree);
	temp.show();
	cout << endl;
	bin_tree.show();
	cout << endl;
	cout << "Press any key";
	SLOW;
	clear();
	binary.show();
	MEDIUM;
	clear();
	inter.show();
	inter.next();
	MEDIUM;
	clear();
	expr.show();
	MEDIUM;
	clear();
	my_menu choose({ "& and","| or","+ xor","! not","- implication","~ equivaalence","1 true","0 false","new variable" });
	my_bin_tree expression;
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.show();
	expression.append_expr('&', expression.vars);
	MEDIUM;
	clear();
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.next();
	choose.show();
	expression.append_expr('|', expression.vars);
	MEDIUM;
	for (size_t i = 0; i < 7; i++)
	{
		clear();
		expression.expr_show();
		std::cout << std::endl;
		std::cout << "What you want to add?";
		choose.next();
		choose.show();
		FAST;
	}
	clear();
	expression.append_expr('a', expression.vars);
	choose.push_back("a");
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.show();
	MEDIUM;
	clear();
	expression.append_expr('b', expression.vars);
	choose.push_back("b");
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.show();
	MEDIUM;
	clear();
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.next();
	choose.show();
	MEDIUM;
	clear();
	expression.append_expr('a', expression.vars);
	expression.expr_show();
	std::cout << std::endl;
	std::cout << "What you want to add?";
	choose.show();
	cout << endl << endl << "Your expression successfully saved" << endl << "Press any key";
	SLOW;
	clear();
	expr.show();
	expr.next();
	MEDIUM;
	clear();
	expr.show();
	MEDIUM;
	clear();
	cout << "Your expression: ";
	expression.expr_show();
	cout << endl << "Press any key";
	SLOW;
	clear();
	expr.show();
	expr.next();
	MEDIUM;
	clear();
	expr.show();
	MEDIUM;
	clear();
	cout << "Your expression before simplification: ";
	expression.expr_show();
	cout << endl;
	cout << "After simplification: ";
	expression.simplify();
	expression.expr_show();
	cout << endl;
	cout << endl << "Press any key";
	SLOW;
	clear();
	expr.show();
	expr.next();
	MEDIUM;
	clear();
	expr.show();
	MEDIUM;
	clear();
	expression.expr_show();
	cout << endl;
	for (size_t i = 0; i < expression.vars.size(); i += 2)
	{
		std::cout << char(expression.vars[i]) << ": ";
		MEDIUM;
		cout << '1';
		FAST;
	}
	expression.simplify();
	cout << endl << "Answer: ";
	expression.expr_show();
	cout << endl << "Press any key";
	SLOW;
	clear();
	cout << "Demo mode completed, press any key";
	_getch();
	return start_menu();
}

void usual_tree_creating()
{
	my_tree usual_tree;
	return usual_tree_menu(usual_tree);
}

void usual_tree_menu(my_tree& usual_tree)
{
	my_menu usual({ "Add element","Delete element", "Show tree" });
	void(*usual_funcs[])(my_tree & usual_tree) = { usual_tree_add_menu,usual_tree_delete_menu, usual_tree_show_menu };
	int key;

	while (1) {
		clear();
		usual.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: usual.prev(); break;
			case DOWN: usual.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return usual_funcs[usual.cur()](usual_tree);
		}
		else if (key == ESC) {
			usual_tree.~my_tree();
			return inter_menu();
		}
	}
}

void binary_tree_menu(my_bin_tree& binary_tree)
{
	my_menu bin_tr_m({ "Push element","Show tree", "Build threaded tree" });
	void(*bin_funcs[])(my_bin_tree & binary_tree) = { binary_tree_add_menu, binary_tree_show_menu, threaded_tree_menu };
	int key;

	while (1) {
		clear();
		bin_tr_m.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: bin_tr_m.prev(); break;
			case DOWN: bin_tr_m.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return bin_funcs[bin_tr_m.cur()](binary_tree);
		}
		else if (key == ESC) {
			binary_tree.~my_bin_tree();
			return inter_menu();
		}
	}
}

void usual_tree_delete_menu(my_tree& usual_tree)
{
	clear();
	path_t path;
	if (usual_tree.is_empty())
	{
		cout << "Tree is empty\n";
		cout << "Press any key to continue";
		_getch();
		return usual_tree_menu(usual_tree);
	}
	else
	{
		usual_tree.show();
		cout << endl;
		cout << "Input size of a path: ";
		int size = -1;
		while (size < 0) {
			get_data(size);
			if (size < 0)
				cout << "Try again: ";
		}
		int step;
		if (size > 0)
			cout << "Input steps: ";
		for (size_t i = 0; i < size; i++)
		{
			get_data(step);
			path.push_back(step);
		}
		cin.ignore(BUFSIZ, '\n');

		if (path.size())
			cout << "path: ";
		for (size_t i = 0; i < path.size(); i++)
		{
			cout << path[i] << (i == path.size() - 1 ? '\n' : ',');
		}
	}
	my_tree* removable;
	try
	{
		removable = usual_tree.remove(path);
		cout << "Your tree after deleting: ";
		try
		{
			usual_tree.show();
		}
		catch (tree_exception& e)
		{
			cout << e.what();
		}
		cout << endl;

		cout << "Deleted part: ";
		try
		{
			removable->show();
			delete removable;
		}
		catch (tree_exception& e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	catch (tree_exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
	cout << "Press any key to continue";
	_getch();
	return usual_tree_menu(usual_tree);
}

void usual_tree_add_menu(my_tree& usual_tree)
{
	clear();
	path_t path;
	if (usual_tree.is_empty())
	{
		cout << "Tree is empty\n";
	}
	else
	{
		usual_tree.show();
		cout << endl;
		cout << "Input size of a path: ";
		int size = -1;
		while (size < 0) {
			get_data(size);
			if (size < 0)
				cout << "Try again: ";
		}
		int step;
		if (size > 0)
			cout << "Input steps: ";
		for (size_t i = 0; i < size; i++)
		{
			get_data(step);
			path.push_back(step);
		}
		cin.ignore(BUFSIZ, '\n');

		if (path.size())
			cout << "path: ";
		for (size_t i = 0; i < path.size(); i++)
		{
			cout << path[i] << (i == path.size() - 1 ? '\n' : ',');
		}
	}
	int val;
	cout << "Input value: ";
	get_data(val);
	cin.ignore(BUFSIZ, '\n');
	try
	{
		usual_tree.append(path, val);
	}
	catch (tree_exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
	cout << "Press any key to continue";
	_getch();
	return usual_tree_menu(usual_tree);
}

void usual_tree_show_menu(my_tree& usual_tree)
{
	cout << "Your tree: ";
	try
	{
		usual_tree.show();
	}
	catch (tree_exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
	cout << endl << "Press any key";
	_getch();
	return usual_tree_menu(usual_tree);
}

void binary_tree_creating()
{
	my_bin_tree binary_tree;
	return binary_tree_menu(binary_tree);
}

void binary_tree_add_menu(my_bin_tree& binary_tree)
{
	clear();
	if (binary_tree.is_empty())
	{
		cout << "Tree is empty\n";
	}
	else
	{
		binary_tree.show();
		cout << endl;
	}
	int val;
	cout << "Input value: ";
	get_data(val);
	cin.ignore(BUFSIZ, '\n');
	try
	{
		binary_tree.push(val);
	}
	catch (tree_exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
	cout << "Press any key to continue";
	_getch();
	return binary_tree_menu(binary_tree);
}

void binary_tree_show_menu(my_bin_tree& binary_tree)
{
	cout << "Your tree: ";
	try
	{
		binary_tree.show();
	}
	catch (tree_exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
	cout << endl << "Press any key";
	_getch();
	return binary_tree_menu(binary_tree);
}

void threaded_tree_menu(my_bin_tree& binary_tree)
{
	if (binary_tree.is_empty())
	{
		cout << "Your tree is empty" << endl;
	}
	else
	{
		threaded_tree temp(binary_tree);
		temp.show();
		cout << endl;
		binary_tree.show();
		cout << endl;
	}
	cout << "Press any key";
	_getch();
	return binary_tree_menu(binary_tree);
}

void expression_creating()
{
	my_bin_tree expression;
	return expression_menu(expression);
}

void expression_menu(my_bin_tree& expression)
{
	my_menu expr({ "Input expression","Show expression", "Simplify expression", "Solve expression" });
	void(*expr_funcs[])(my_bin_tree & expression) = { expr_input_menu, expr_show_menu, expr_simplify_menu, expr_solve_menu };
	int key;

	while (1) {
		clear();
		expr.show();

		key = _getch();

		if (key == ARROW)
		{
			key = _getch();
			switch (key) {
			case UP: expr.prev(); break;
			case DOWN: expr.next(); break;
			default: break;
			}
		}
		else if (key == ENTER) {
			return expr_funcs[expr.cur()](expression);
		}
		else if (key == ESC) {
			expression.~my_bin_tree();
			return inter_menu();
		}
	}
}

void expr_input_menu(my_bin_tree& expression)
{
	expression.get_expr();
	cout << endl << endl << "Your expression successfully saved" << endl << "Press any key";
	_getch();
	return expression_menu(expression);
}

void expr_show_menu(my_bin_tree& expression)
{
	cout << "Your expression: ";
	expression.expr_show();
	cout << endl << "Press any key";
	_getch();
	return expression_menu(expression);
}

void expr_simplify_menu(my_bin_tree& expression)
{
	if (expression.is_empty())
		cout << "Your expression is empty";
	else
	{
		cout << "Your expression before simplification: ";
		expression.expr_show();
		cout << endl;
		cout << "After simplification: ";
		expression.simplify();
		expression.expr_show();
		cout << endl;
	}

	cout << endl << "Press any key";
	_getch();
	return expression_menu(expression);
}

void expr_solve_menu(my_bin_tree& expression)
{
	if (expression.is_empty())
		cout << "Your expression is empty";
	else
	{
		expression.expr_show();
		cout << endl;
		expression.solve();
		cout << endl << "Answer: ";
		expression.expr_show();
	}

	cout << endl << "Press any key";
	_getch();
	return expression_menu(expression);
}