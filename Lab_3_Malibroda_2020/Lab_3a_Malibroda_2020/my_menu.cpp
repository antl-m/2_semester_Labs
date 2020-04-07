#include "my_menu.h"

my_menu::my_menu(std::vector<std::string> puncts)
{
	this->puncts = puncts;
	current = 0;
}

void my_menu::show()
{
	std::cout << std::endl;
	for (std::size_t i = 0; i < puncts.size(); i++)
	{
		std::cout << (i==current?">>> ":"   ") << i+1<<". " << puncts[i] << std::endl;
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

std::size_t my_menu::cur()
{
	return current;
}

void clear()
{
	system("CLS");
}