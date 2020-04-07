#include "my_tree.h"
#include"Lab_4.h"

const char operator_list[] = { '&','|','!','+','-','~' };

my_tree_node* my_tree::node_at_val(int val)
{
	if (root)
	{
		if (root->val == val) return root;

		my_tree_node* current = nullptr;
		my_tree subtree;
		subtree.root = nullptr;

		for (size_t i = 0; i < root->sons.size(); i++)
		{
			subtree.root = root->sons[i];
			current = subtree.node_at_val(val);
			if (current) return current;
		}
	}
	return nullptr;
}

int my_tree::val_at_path(path_t path)
{
	my_tree_node* current;
	current = root;
	if (current)
	{
		for (size_t i = 0; i < path.size(); i++)
		{
			if (current->sons.size() < path[i] || path[i] < 0)
				throw tree_exception("Invalid path");
			else if (current->sons[path[i]])
				current = current->sons[path[i]];
			else throw tree_exception("Son is nullptr");
		}
	}
	else throw tree_exception("root of tree is nullptr");
	return current->val;
}

path_t my_tree::path_of_val(int val)
{
	path_t res;
	my_tree_node* current;
	current = node_at_val(val);
	if (current)
	{
		while (current->father)
		{
			for (size_t i = 0; i < current->father->sons.size(); i++)
			{
				if (current->father->sons[i] == current)
				{
					res.push_front(i);
					break;
				}
			}
			current = current->father;
		}
		return res;
	}
	return { -1 };
}

void my_tree::append(path_t path, int val)			//	Path to father element
{
	my_tree_node* addin = new my_tree_node;
	addin->val = val;
	my_tree_node* current = root;
	if (current)
	{
		for (size_t i = 0; i < path.size(); i++)
		{
			if (current->sons.size() <= path[i] || path[i] < 0)
				throw tree_exception("Invalid path");
			else if (current->sons[path[i]])
				current = current->sons[path[i]];
			else throw tree_exception("Son is nullptr");
		}
		current->sons.push_back(addin);
		addin->father = current;
	}
	else
	{
		root = addin;
	}
}

void my_tree::show()
{
	if (root)
	{
		std::cout << root->val;
	}
	else throw tree_exception("Tree is empty");

	if (root->sons.size() != 0)
	{
		my_tree subtree;
		std::cout << "( ";
		for (size_t i = 0; i < root->sons.size(); i++)
		{
			subtree.root = root->sons[i];
			subtree.show();
			if (i != root->sons.size() - 1)
				std::cout << ", ";
		}
		std::cout << " )";
		subtree.root = nullptr;
	}
}

bool my_tree::is_empty()
{
	if (root)
		return false;
	else
		return true;
}

my_tree::~my_tree()
{
	erase_node(root);
}

my_tree* my_tree::remove(path_t path)
{
	my_tree_node* current = root;
	my_tree* removable = new my_tree;
	if (current)
	{
		for (size_t i = 0; i < path.size(); i++)
		{
			if (current->sons.size() < path[i] || path[i] < 0)
				throw tree_exception("Invalid path");
			else if (current->sons[path[i]])
				current = current->sons[path[i]];
			else throw tree_exception("Son is nullptr");
		}
		if (path.size() != 0)
			current->father->sons.erase(current->father->sons.begin() + path[path.size() - 1]);
		removable->root = current;
		if (path.size() == 0)
			root = nullptr;
		removable->root->father = nullptr;
		return removable;
	}
	else throw tree_exception("Used remove on empty tree");
}

void my_bin_tree::push(int val)
{
	bin_tree_node* current = root;
	bin_tree_node* addin = new bin_tree_node;
	addin->val = val;
	while (current)
	{
		if (val < current->val)
		{
			if (current->l_son)
				current = current->l_son;
			else
			{
				current->l_son = addin;
				addin->father = current;
				return;
			}
		}
		else
		{
			if (current->r_son)
				current = current->r_son;
			else
			{
				current->r_son = addin;
				addin->father = current;
				return;
			}
		}
	}
	root = addin;
}

void my_bin_tree::show()
{
	if (root)
	{
		std::cout << root->val;
	}
	else throw tree_exception("Tree is empty");

	if (root->l_son || root->r_son)
	{
		my_bin_tree subtree;
		std::cout << "( ";
		if (root->l_son)
		{
			subtree.root = root->l_son;
			subtree.show();

			if (root->r_son)
				std::cout << ", ";
		}
		if (root->r_son)
		{
			subtree.root = root->r_son;
			subtree.show();
		}
		std::cout << " )";
		subtree.root = nullptr;
	}
}

void my_bin_tree::append(path_t path, int val)			//	Path to father element
{
	bin_tree_node* addin = new bin_tree_node;
	addin->val = val;
	bin_tree_node* current = root;
	if (current)
	{
		for (size_t i = 0; i < path.size(); i++)
		{
			if (path[i] == 0 && current->l_son)
				current = current->l_son;
			else if (path[i] == 1 && current->r_son)
				current = current->r_son;
			else throw tree_exception("Invalid path");
		}
		if (current->l_son && current->r_son)
			throw tree_exception("There are both sons");
		else if (current->l_son)
			current->r_son = addin;
		else
			current->l_son = addin;
		addin->father = current;
	}
	else
	{
		root = addin;
	}
	if (val >= 'a' && val <= 'z')
	{
		bool is = false;
		for (size_t i = 0; i < vars.size(); i += 2)
		{
			if (val == vars[i])
				is = true;
		}
		if (!is)
		{
			vars.push_back(val);
			vars.push_back(-1);
		}
	}
}

void my_bin_tree::expr_show()
{
	my_bin_tree subexpr;
	if (!root)
	{
		std::cout << "__";
	}
	else if ((root->val >= 'a' && root->val <= 'z') || root->val < 2)
	{
		if (root->val < 2)
			std::cout << root->val;
		else
			std::cout << char(root->val);
	}
	else
	{
		std::cout << "(";
		if (root->val == '!')
		{
			std::cout << "!";
			subexpr.root = root->l_son;
			subexpr.expr_show();
		}
		else
		{
			subexpr.root = root->l_son;
			subexpr.expr_show();
			std::cout << char(root->val);
			subexpr.root = root->r_son;
			subexpr.expr_show();
		}
		std::cout << ")";
	}
	subexpr.root = nullptr;
}

void my_bin_tree::simpl(std::deque<int> vars)
{
	bin_tree_node* add;
	my_bin_tree* subtree = new my_bin_tree;
	if (root)
	{
		if (root->l_son)
		{
			subtree->root = root->l_son;
			subtree->simpl(vars);
			subtree->root = root->r_son;
			subtree->simpl(vars);

			switch (root->val)
			{
			case '&':
				if (root->l_son->val == 0
					|| root->r_son->val == 0)
				{
					root->val = 0;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val == 1)
				{
					bin_tree_node* del = root->r_son;
					erase_node(root->l_son);
					root->r_son = del->r_son;
					root->l_son = del->l_son;
					root->val = del->val;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->r_son->val == 1)
				{
					bin_tree_node* del = root->l_son;
					erase_node(root->r_son);
					root->r_son = del->r_son;
					root->l_son = del->l_son;
					root->val = del->val;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->l_son->val == '!'
					&& root->l_son->l_son->val == root->r_son->val
					&& root->r_son->val >= 'a'
					&& root->r_son->val <= 'z')
				{
					root->val = 0;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->r_son->val == '!'
					&& root->r_son->l_son->val == root->l_son->val
					&& root->l_son->val >= 'a'
					&& root->l_son->val <= 'z')
				{
					root->val = 0;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val >= 'a'
					&& root->l_son->val <= 'z'
					&& root->r_son->val == '|'
					&& (root->r_son->l_son->val == root->l_son->val || root->r_son->r_son->val == root->l_son->val))
				{
					root->val = root->l_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->r_son->val >= 'a'
					&& root->r_son->val <= 'z'
					&& root->l_son->val == '|'
					&& (root->l_son->l_son->val == root->r_son->val || root->l_son->r_son->val == root->r_son->val))
				{
					root->val = root->r_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val >= 'a' && root->l_son->val <= 'z' && root->l_son->val == root->r_son->val)
				{
					root->val = root->l_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				break;
			case '|':
				if (root->l_son->val == 1 || root->r_son->val == 1)
				{
					root->val = 1;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val == 0)
				{
					bin_tree_node* del = root->r_son;
					erase_node(root->l_son);
					root->r_son = del->r_son;
					root->l_son = del->l_son;
					root->val = del->val;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->r_son->val == 0)
				{
					bin_tree_node* del = root->l_son;
					erase_node(root->r_son);
					root->r_son = del->r_son;
					root->l_son = del->l_son;
					root->val = del->val;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->l_son->val == '!'
					&& root->l_son->l_son->val == root->r_son->val
					&& root->r_son->val >= 'a' && root->r_son->val <= 'z')
				{
					root->val = 1;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->r_son->val == '!'
					&& root->r_son->l_son->val == root->l_son->val
					&& root->l_son->val >= 'a' && root->l_son->val <= 'z')
				{
					root->val = 1;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val >= 'a'
					&& root->l_son->val <= 'z'
					&& root->r_son->val == '&'
					&& (root->r_son->l_son->val == root->l_son->val || root->r_son->r_son->val == root->l_son->val))
				{
					root->val = root->l_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->r_son->val >= 'a'
					&& root->r_son->val <= 'z'
					&& root->l_son->val == '&'
					&& (root->l_son->l_son->val == root->r_son->val || root->l_son->r_son->val == root->r_son->val))
				{
					root->val = root->r_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val >= 'a' && root->l_son->val <= 'z' && root->l_son->val == root->r_son->val)
				{
					root->val = root->l_son->val;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				break;
			case '!':
				if (root->l_son->val == 1)
				{
					root->val = 0;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val == 0)
				{
					root->val = 1;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val == '!')
				{
					erase_node(root->r_son);
					bin_tree_node* del = root->l_son;
					root->val = del->l_son->val;
					root->l_son = del->l_son->l_son;
					root->r_son = del->l_son->r_son;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					del->l_son->l_son = nullptr;
					del->l_son->r_son = nullptr;
					erase_node(del);
				}
				break;
			case '+':
				if (root->l_son->val == 0)
				{
					erase_node(root->l_son);
					bin_tree_node* del = root->r_son;
					root->val = del->val;
					root->l_son = del->l_son;
					root->r_son = del->r_son;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->r_son->val == 0)
				{
					erase_node(root->r_son);
					bin_tree_node* del = root->l_son;
					root->val = del->val;
					root->l_son = del->l_son;
					root->r_son = del->r_son;
					if (root->l_son)
						root->l_son->father = root;
					if (root->r_son)
						root->r_son->father = root;
					delete del;
				}
				else if (root->l_son->val == 1)
				{
					erase_node(root->l_son);
					root->val = '!';
					root->l_son = root->r_son;
					root->r_son = nullptr;
					this->simpl(vars);
				}
				else if (root->r_son->val == 1)
				{
					erase_node(root->r_son);
					root->val = '!';
					root->r_son = nullptr;
					this->simpl(vars);
				}
				else if (root->l_son->val >= 'a' && root->l_son->val <= 'z' && root->l_son->val == root->r_son->val)
				{
					root->val = 0;
					erase_node(root->l_son);
					erase_node(root->r_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->l_son->val == '!'
					&& root->l_son->l_son->val == root->r_son->val
					&& root->r_son->val >= 'a'
					&& root->r_son->val <= 'z')
				{
					root->val = 1;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				else if (root->r_son->val == '!'
					&& root->r_son->l_son->val == root->l_son->val
					&& root->l_son->val >= 'a'
					&& root->l_son->val <= 'z')
				{
					root->val = 1;
					erase_node(root->r_son);
					erase_node(root->l_son);
					root->l_son = nullptr;
					root->r_son = nullptr;
				}
				break;
			case '-':
				root->val = '|';
				add = new bin_tree_node;
				add->val = '!';
				add->l_son = root->l_son;
				root->l_son = add;
				add->father = root;
				this->simpl(vars);
				break;
			case '~':
				add = new bin_tree_node;
				add->val = '+';
				add->l_son = root->l_son;
				add->r_son = root->r_son;
				add->father = root;
				root->val = '!';
				root->l_son = add;
				root->r_son = nullptr;
				this->simpl(vars);
				break;
			default:
				break;
			}
			subtree->root = nullptr;
			delete subtree;
		}
		else
		{
			for (size_t i = 0; i < vars.size(); i += 2)
			{
				if (root->val == vars[i] && vars[i + 1] != -1)
					root->val = vars[i + 1];
			}
		}
	}
}

bool my_bin_tree::is_empty()
{
	if (root)
		return false;
	else
		return true;
}

void my_bin_tree::get_expr()
{
	erase_node(root);
	root = nullptr;
	bool incompl = true;
	my_menu choose({ "& and","| or","+ xor","! not","- implication","~ equivaalence","1 true","0 false","new variable" });
	std::deque<int> operands_list = { '&','|','+','!','-','~',1,0,'a' };
	int key;
	while (incompl)
	{
		clear();
		expr_show();
		std::cout << std::endl;
		std::cout << "What you want to add?";
		choose.show();
		key = _getch();
		if (key == 224)// { UP = 72, DOWN = 80, ENTER = 13, ESC = 27, ARROW = 224 };
		{
			key = _getch();
			switch (key) {
			case 72: choose.prev(); break;
			case 80: choose.next(); break;
			default: break;
			}
		}
		else if (key == 13) {
			if (choose.cur() == 8)
			{
				incompl = append_expr(operands_list[8], vars);
				std::string tmp = "";
				tmp += char(operands_list[8]);
				choose.push_back(tmp);
				operands_list.push_back(operands_list[8]++);
			}
			else
				incompl = append_expr(operands_list[choose.cur()], vars);
		}
		else if (key == 27) {
			erase_node(root);
			break;
		}
	}
	return;
}

bool my_bin_tree::append_expr(int val, std::deque<int>& vars)
{
	if (root)
	{
		if ((root->val >= 'a' && root->val <= 'z') || root->val < 2)
		{
			return false;
		}
		else
		{
			my_bin_tree subtree;
			if (root->l_son)
			{
				subtree.root = root->l_son;
				if (subtree.append_expr(val, vars))
				{
					subtree.root = nullptr;
					return true;
				}
				else
				{
					subtree.root = nullptr;
					if (root->val == '!')
						return false;
					else
					{
						if (root->r_son)
						{
							subtree.root = root->r_son;
							if (subtree.append_expr(val, vars))
							{
								subtree.root = nullptr;
								return true;
							}
							else
							{
								subtree.root = nullptr;
								return false;
							}
						}
						else
						{
							root->r_son = new bin_tree_node;
							root->r_son->val = val;
							if (val >= 'a' && val <= 'z' && !is_val_in_vars(val, vars))
							{
								vars.push_back(val);
								vars.push_back(-1);
							}
							return true;
						}
					}
				}
			}
			else
			{
				root->l_son = new bin_tree_node;
				root->l_son->val = val;
				if (val >= 'a' && val <= 'z' && !is_val_in_vars(val, vars))
				{
					vars.push_back(val);
					vars.push_back(-1);
				}
				return true;
			}
		}
	}
	else
	{
		root = new bin_tree_node;
		root->val = val;
		if (val >= 'a' && val <= 'z' && !is_val_in_vars(val, vars))
		{
			vars.push_back(val);
			vars.push_back(-1);
		}
		return true;
	}
}

void my_bin_tree::solve()
{
	std::cout << std::endl;
	for (size_t i = 0; i < vars.size(); i += 2)
	{
		std::cout << char(vars[i]) << ": ";
		get_data(vars[i + 1]);
		if (vars[i + 1] != 0)
			vars[i + 1] = 1;
	}
	simplify();
}

void my_bin_tree::simplify()
{
	simpl(vars);
}

my_bin_tree::~my_bin_tree()
{
	erase_node(root);
}

threaded_node* thrd_from_bin(bin_tree_node* input, threaded_node* prev, threaded_node* next)
{
	threaded_node* output;
	output = new threaded_node;
	output->val = input->val;

	if ((output->is_l_son = (input->l_son != NULL)))
		output->l_son = thrd_from_bin(input->l_son, prev, output);
	else
		output->l_son = prev;

	if ((output->is_r_son = (input->r_son != NULL)))
		output->r_son = thrd_from_bin(input->r_son, output, next);
	else
		output->r_son = next;

	return output;
}

void threaded_tree::print_node(int& i)
{
	if (root)
	{
		if (root->l_son || root->r_son)
		{
			threaded_tree subtree;
			if (root->l_son)
			{
				if (root->is_l_son)
				{
					std::cout << "( ";
					subtree.root = this->root->l_son;
					subtree.print_node(i);
					std::cout << " )";
				}
				else std::cout << i - 1 << '.' << root->l_son->val << "<-";
			}
			std::cout << i++ << '.' << root->val;
			if (root->r_son)
			{
				if (root->is_r_son)
				{
					std::cout << "( ";
					subtree.root = root->r_son;
					subtree.print_node(i);
					std::cout << " )";
				}
				else std::cout << "->" << i << '.' << root->r_son->val;
			}
			subtree.root = nullptr;
		}
	}
	else throw tree_exception("Tree is empty");
}

threaded_tree::threaded_tree() {};

threaded_tree::threaded_tree(my_bin_tree& input)
{
	if (input.root)
		root = thrd_from_bin(input.root, nullptr, nullptr);
}

void threaded_tree::show()
{
	int a = 1;
	print_node(a);
}

threaded_tree::~threaded_tree()
{
	erase_node(root);
}

void erase_node(my_tree_node* node)
{
	if (node)
	{
		for (size_t i = 0; i < node->sons.size(); i++)
		{
			erase_node(node->sons[i]);
		}
		node->sons.~deque();
		delete node;
		node = nullptr;
	}

}

void erase_node(bin_tree_node* node)
{
	if (node)
	{
		erase_node(node->l_son);
		erase_node(node->r_son);

		delete node;
		node = nullptr;
	}
}

void erase_node(threaded_node* node)
{
	if (node)
	{
		if (node->is_l_son)
			erase_node(node->l_son);
		if (node->is_r_son)
			erase_node(node->r_son);

		delete node;
		node = nullptr;
	}
}

bool is_val_in_vars(int val, std::deque<int> vars)
{
	for (size_t i = 0; i < vars.size(); i += 2)
	{
		if (val == vars[i])
			return true;
	}
	return false;
}