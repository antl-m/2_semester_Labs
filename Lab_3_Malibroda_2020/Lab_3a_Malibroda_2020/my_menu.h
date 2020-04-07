#pragma once
#include <iostream>
#include <vector>
#include <string>

class my_menu
{
private:
	std::vector<std::string> puncts;
	std::size_t current;
public:
	my_menu(std::vector<std::string> puncts);

	void show();

	void next();

	void prev();

	std::size_t cur();
};

void clear();