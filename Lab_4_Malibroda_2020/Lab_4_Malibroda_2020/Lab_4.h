#pragma once
#include<iostream>
#include"my_tree.h"

template<class T>
void get_data(T& val)
{
	while (1)
	{
		std::cin >> val;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			std::cout << "Try again: ";
		}
		else
			break;
	}
}

void start_menu();
void inter_menu();
void demo_mode();

void usual_tree_creating();
void usual_tree_menu(my_tree& usual_tree);
void binary_tree_menu(my_bin_tree& binary_tree);
void usual_tree_add_menu(my_tree& usual_tree);
void usual_tree_delete_menu(my_tree& usual_tree);
void usual_tree_show_menu(my_tree& usual_tree);
void binary_tree_add_menu(my_bin_tree& binary_tree);
void binary_tree_creating();
void binary_tree_show_menu(my_bin_tree& binary_tree);
void threaded_tree_menu(my_bin_tree& binary_tree);
void expression_creating();
void expression_menu(my_bin_tree& expression);
void expr_input_menu(my_bin_tree& expression);
void expr_show_menu(my_bin_tree& expression);
void expr_simplify_menu(my_bin_tree& expression);
void expr_solve_menu(my_bin_tree& expression);