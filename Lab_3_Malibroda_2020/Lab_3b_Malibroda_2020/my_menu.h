#pragma once
#include <iostream>
#include <vector>
#include <string>

class my_menu
{
private:
	std::vector<std::string> puncts;
	int current;
public:
	my_menu(std::vector<std::string> puncts);

	my_menu();

	void show();

	void next();

	void prev();

	void pop_back();

	void push_back(std::string str);

	int cur();

	bool is_empty();

	std::string punct(std::size_t pos);
};

void clear();