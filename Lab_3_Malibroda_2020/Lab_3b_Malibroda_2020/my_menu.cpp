#include "my_menu.h"

my_menu::my_menu(std::vector<std::string> puncts)
{
	this->puncts = puncts;
	current = 0;
}

my_menu::my_menu()
{
	current = -1;
};

void my_menu::show()
{
	std::cout << std::endl;
	for (std::size_t i = 0; i < puncts.size(); i++)
	{
		std::cout << (i == current ? ">>> " : "   ") << i + 1 << ". " << puncts[i] << std::endl;
	}
	std::cout << std::endl;
}

void my_menu::next()
{
	current++;
	current %= puncts.size();
}

void my_menu::prev()
{
	current--;
	current += puncts.size();
	current %= puncts.size();
}

int my_menu::cur()
{
	return current;
}

void my_menu::pop_back()
{
	puncts.pop_back();
}

void my_menu::push_back(std::string str)
{
	puncts.push_back(str);
}

bool my_menu::is_empty()
{
	return !(puncts.size());
}

std::string my_menu::punct(std::size_t pos)
{
	return puncts[pos];
}

void clear()
{
	system("CLS");
}