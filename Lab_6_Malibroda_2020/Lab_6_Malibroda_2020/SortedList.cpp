#include "SortedList.h"
#include <random>
#include <algorithm>

using std::string;
using std::vector;

string randstr() {
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> siz(1, 10);
	int size = siz(rand);
	std::uniform_int_distribution<> highletter(65, 90);
	std::uniform_int_distribution<> boolean(0, 1);
	string res(size, ' ');
	for (size_t i = 0; i < size; i++) {
		res[i] = highletter(rd) + 32 * boolean(rd);
	}
	return res;
}

int SortedList::Size() const { return size; }
void SortedList::Random(int N) {
	for (size_t i = 0; i < N; i++) {
		Insert(randstr());
	}
}
SortedList::~SortedList() {};

std::ostream& operator<<(std::ostream& out, const SortedList& list) {
	list.Print(out);
	return out;
}

LinkedList::LinkedList() {}
LinkedList::LinkedList(int N) {
	Random(N);
}
void LinkedList::Insert(const string& val) {
	Node* cur = head;
	Node* prev = nullptr;
	Node* add = new Node;
	add->val = val;
	while (cur && !(add->val < cur->val)) {
		prev = cur;
		cur = cur->next;
	}
	add->next = cur;
	if (prev)
		prev->next = add;
	else
		head = add;
	size++;
}
void LinkedList::Print(std::ostream& out) const {
	for (Node* iter = head; iter; iter = iter->next) {
		out << iter->val << std::endl;
	}
}
void LinkedList::ForEach(void (*foo)(string&)) {
	Node* cur = head;
	while (cur) {
		foo(cur->val);
		cur = cur->next;
	}
}
bool LinkedList::Erase(const string& val) {
	Node* cur = head;
	Node* prev = nullptr;

	while (cur && !(cur->val == val)) {
		prev = cur;
		cur = cur->next;
	}
	if (cur) {
		(prev ? prev->next : head) = cur->next;
		cur->next = nullptr;
		delete cur;
		size--;
		return true;
	}
	else {
		return false;
	}
}
bool LinkedList::Find(const string& val) const {
	Node* cur = head;
	while (cur && !(cur->val == val)) {
		cur = cur->next;
	}
	return bool(cur);
}
vector<string> LinkedList::Find(const string& first, const string& last) const {
	Node* cur = head;
	vector<string> res;
	while (cur && !(first <= cur->val)) {
		cur = cur->next;
	}
	while (cur && !(last < cur->val)) {
		res.push_back(cur->val);
		cur = cur->next;
	}
	return res;
}
LinkedList::~LinkedList() {
	Node* cur = nullptr;
	while (head) {
		cur = head->next;
		delete head;
		head = cur;
	}
}


ArrayList::ArrayList() {
	arr = new string[max_size];
}
ArrayList::ArrayList(int N) {
	arr = new string[max_size];
	Random(N);
}
void ArrayList::upsize() {
	max_size *= 2;
	string* new_arr = new string[max_size];
	std::copy(&arr[0], &arr[size], new_arr);
	delete[] arr;
	arr = new_arr;
}
void ArrayList::downsize() {
	max_size /= 2;
	string* new_arr = new string[max_size];
	std::copy(&arr[0], &arr[size], new_arr);
	delete[] arr;
	arr = new_arr;
}
void ArrayList::Insert(const string& val) {
	if (size == max_size - 1)
		upsize();
	int cur = 0;
	while (cur < size && !(val < arr[cur])) {
		cur++;
	}
	if (cur < size) {
		for (size_t i = size; i > cur; i--) {
			arr[i] = arr[i - 1];
		}
	}
	arr[cur] = val;
	size++;
}
void ArrayList::Print(std::ostream& out) const {
	for (size_t i = 0; i < size; i++) {
		out << arr[i] << std::endl;
	}
}
void ArrayList::ForEach(void (*foo)(string&)) {
	for (size_t i = 0; i < size; i++) {
		foo(arr[i]);
	}
}
bool ArrayList::Erase(const string& val) {
	int cur = 0;

	while (cur < size && !(arr[cur] == val)) {
		cur++;
	}
	if (cur >= size) {
		return false;
	}
	else {
		for (size_t i = cur; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		if (size == max_size / 4)
			downsize();
		return true;
	}
}
bool ArrayList::Find(const string& val) const {
	int cur = 0;
	while (cur < size && !(arr[cur] == val)) {
		cur++;
	}
	return (cur < size);
}
vector<string> ArrayList::Find(const string& first, const string& last) const {
	int cur = 0;
	vector<string> res;
	while (cur < size && !(first <= arr[cur])) {
		cur++;
	}
	while (cur < size && !(last < arr[cur])) {
		res.push_back(arr[cur]);
		cur++;
	}
	return res;
}
ArrayList::~ArrayList() {
	delete[] arr;
}


TreeList::TreeList() {};
TreeList::TreeList(int N) {
	Random(N);
}
void TreeList::Insert(const string& val) {
	TreeNode* cur = root;
	TreeNode* father = nullptr;
	while (cur) {
		father = cur;
		cur = (val < cur->val ? cur->lson : cur->rson);
	}
	cur = new TreeNode;
	cur->val = val;
	cur->father = father;
	if (!father)
		root = cur;
	else {
		(val < father->val ? father->lson : father->rson) = cur;
	}
	size++;
}
void print_tree_node(std::ostream& out, TreeNode* node) {
	if (node) {
		print_tree_node(out, node->lson);
		out << node->val << std::endl;
		print_tree_node(out, node->rson);
	}
}
void TreeList::Print(std::ostream& out) const {
	print_tree_node(out, root);
}
void for_each_node(void foo(string&), TreeNode* node) {
	if (node) {
		for_each_node(foo, node->lson);
		foo(node->val);
		for_each_node(foo, node->rson);
	}
}
void TreeList::ForEach(void (*foo)(string&)) {
	for_each_node(foo, root);
}
bool TreeList::erase_val_subtr(TreeNode* node, const string& val) {
	if (!node)
		return false;

	if (val < node->val) {
		return erase_val_subtr(node->lson, val);
	}
	else if (val > node->val) {
		return erase_val_subtr(node->rson, val);
	}
	else {
		if (node->lson && node->rson) {
			TreeNode* cur = node->lson;
			while (cur->rson)
				cur = cur->rson;
			std::swap(cur->val, node->val);
			return erase_val_subtr(cur, val);
		}
		else {
			TreeNode* father = node->father;
			if (!father) {
				root = (node->lson ? node->lson : node->rson);
				if (root)
					root->father = nullptr;
				delete node;
				return true;
			}
			if (father->lson && father->lson->val == val) {
				father->lson = (node->lson ? node->lson : node->rson);
			}
			else if (father->rson && father->rson->val == val) {
				father->rson = (node->lson ? node->lson : node->rson);
			}
			node->lson = node->rson = node->father = nullptr;
			delete node;
			if (father->lson)
				father->lson->father = father;
			if (father->rson)
				father->rson->father = father;
			return true;
		}
	}
}
bool TreeList::Erase(const string& val) {
	if (erase_val_subtr(root, val)) {
		size--;
		return true;
	}
	else
		return false;
}
bool TreeList::Find(const string& val) const {
	TreeNode* cur = root;
	while (cur && !(cur->val == val)) {
		cur = (val < cur->val ? cur->lson : cur->rson);
	}
	return bool(cur);
}
void vec_from_node(vector<string>& res, TreeNode* node, const string& first, const string& last) {
	if (node) {
		if (node->val >= first)
			vec_from_node(res, node->lson, first, last);
		if (node->val >= first && node->val <= last)
			res.push_back(node->val);
		if (node->val <= last)
			vec_from_node(res, node->rson, first, last);
	}
}
vector<string> TreeList::Find(const string& first, const string& last) const {
	vector<string> res;
	vec_from_node(res, root, first, last);
	return res;
}
void del_node(TreeNode* cur) {
	if (cur) {
		del_node(cur->lson);
		del_node(cur->rson);
		delete cur;
	}
}
TreeList::~TreeList() {
	del_node(root);
}


int bal(TreeNode* node) {
	if (node)
		return (node->lson ? node->lson->height : 0) - (node->rson ? node->rson->height : 0);
	return NULL;
}
void left(TreeNode** node) {
	TreeNode* a = *node;
	TreeNode* b = a->rson;
	a->rson = b->lson;
	b->lson = a;
	if (a->father && a->father->lson && a->father->lson->val == a->val)
		a->father->lson = b;
	else if (a->father)
		a->father->rson = b;
	b->father = a->father;
	a->father = b;
	if (a->rson)
		a->rson->father = a;
	*node = b;
	a->height = 1 + std::max((a->lson ? a->lson->height : 0), (a->rson ? a->rson->height : 0));
	b->height = 1 + std::max((b->lson ? b->lson->height : 0), (b->rson ? b->rson->height : 0));
}
void right(TreeNode** node) {
	TreeNode* a = *node;
	TreeNode* b = a->lson;
	a->lson = b->rson;
	b->rson = a;
	if (a->father && a->father->rson && a->father->rson->val == a->val)
		a->father->rson = b;
	else if (a->father)
		a->father->lson = b;
	b->father = a->father;
	a->father = b;
	if (a->lson)
		a->lson->father = a;
	*node = b;
	a->height = 1 + std::max((a->lson ? a->lson->height : 0), (a->rson ? a->rson->height : 0));
	b->height = 1 + std::max((b->lson ? b->lson->height : 0), (b->rson ? b->rson->height : 0));
}
void dblright(TreeNode** node) {
	left(&((*node)->lson));
	right(node);
}
void dblleft(TreeNode** node) {
	right(&((*node)->rson));
	left(node);
}
bool AVL_node_insert(TreeNode** subtree, const string& val) {
	if (!(*subtree)) {
		(*subtree) = new TreeNode;
		(*subtree)->val = val;
		(*subtree)->height++;
		return true;
	}
	else {
		int height = (*subtree)->height;
		if (val < (*subtree)->val) {
			if (AVL_node_insert(&((*subtree)->lson), val)) {
				(*subtree)->lson->father = (*subtree);
				(*subtree)->height = 1 + std::max(((*subtree)->lson ? (*subtree)->lson->height : 0), ((*subtree)->rson ? (*subtree)->rson->height : 0));
				int balance = bal((*subtree));
				if (balance <= 1) {
					return (*subtree)->height > height;
				}
				else {
					if (bal((*subtree)->lson) > 0)
						right(subtree);
					else
						dblright(subtree);
					return false;
				}
			}
		}
		else {
			if (AVL_node_insert(&(*subtree)->rson, val)) {
				(*subtree)->rson->father = (*subtree);
				(*subtree)->height = 1 + std::max(((*subtree)->lson ? (*subtree)->lson->height : 0), ((*subtree)->rson ? (*subtree)->rson->height : 0));
				int balance = bal((*subtree));
				if (balance >= -1) {
					return (*subtree)->height > height;
				}
				else {
					if (bal((*subtree)->rson) < 0)
						left(subtree);
					else
						dblleft(subtree);
					return false;
				}
			}
		}
	}
}
void AVLList::Insert(const string& val) {
	AVL_node_insert(&root, val);
	size++;
}
bool AVL_node_erase(TreeNode** subtree, const string& val) {
	if (!(*subtree)) {
		return false;
	}
	else {
		int height = (*subtree)->height;
		if (val == (*subtree)->val) {
			if ((*subtree)->lson && (*subtree)->rson) {
				TreeNode* cur = (*subtree);
				if (bal(*subtree) > 0) {
					cur = cur->lson;
					while (cur->rson)
						cur = cur->rson;
				}
				else {
					cur = cur->rson;
					while (cur->lson)
						cur = cur->lson;
				}
				std::swap(cur->val, (*subtree)->val);
				return AVL_node_erase(subtree, val);
			}
			else {
				TreeNode* father = (*subtree)->father;
				(*subtree)->lson = (*subtree)->rson = (*subtree)->father = nullptr;
				delete (*subtree);
				if (val < father->val)
					father->lson = nullptr;
				else
					father->rson = nullptr;
				if (father->lson)
					father->lson->father = father;
				if (father->rson)
					father->rson->father = father;
				father->height = 1 + std::max((father->lson ? father->lson->height : 0), (father->rson ? father->rson->height : 0));
				return true;
			}
		}
		else if (val < (*subtree)->val) {
			if (AVL_node_erase(&((*subtree)->lson), val)) {
				int balance = bal((*subtree));
				if (balance < -1) {
					if (bal((*subtree)->rson) < 0)
						left(subtree);
					else
						dblleft(subtree);
				}
				return true;
			}
			else return false;
		}
		else {
			if (AVL_node_erase(&(*subtree)->rson, val)) {
				int balance = bal((*subtree));
				if (balance > 1) {
					if (bal((*subtree)->lson) > 0)
						right(subtree);
					else
						dblright(subtree);
				}
				return true;
			}
			else return false;
		}
	}
}
bool AVLList::Erase(const string& val) {
	if (AVL_node_erase(&root, val)) {
		size--;
		return true;
	}
	else return false;
}


List23::List23() {};
List23::List23(int N) {
	Random(N);
}
bool isleaf(Node23* node) {
	return !(node->sons[0] || node->sons[1] || node->sons[2] || node->sons[3]);
}
void insert_in_node(Node23** node, const string& val) {
	for (size_t i = 0; i < 3; i++) {
		if ((*node)->vals[i] == "") {
			(*node)->vals[i] = val;
			(*node)->size++;
			break;
		}
	}
	std::sort(&((*node)->vals[0]), &((*node)->vals[3]), [](const string& lhs, const string& rhs)->bool {
		if (lhs == "") return false;
		if (rhs == "") return true;
		return lhs < rhs;
		});
}
bool del_from_node(Node23** node, const string& val) {
	bool res = false;
	for (size_t i = 0; i < 3; i++) {
		if ((*node)->vals[i] == val) {
			(*node)->vals[i] = "";
			(*node)->size--;
			res = true;
			break;
		}
	}
	std::sort(&((*node)->vals[0]), &((*node)->vals[3]), [](const string& lhs, const string& rhs)->bool {
		if (lhs == "") return false;
		if (rhs == "") return true;
		return lhs < rhs;
		});
	return res;
}
void addson(Node23** father, Node23** son) {
	(*son)->father = *father;
	for (size_t i = 0; i < 4; i++) {
		if (!((*father)->sons[i])) {
			(*father)->sons[i] = *son;
			(*son)->father = *father;
			break;
		}
	}

	std::sort(&((*father)->sons[0]), &((*father)->sons[4]), [](Node23* lhs, Node23* rhs)->bool {
		if (lhs == nullptr) return false;
		if (rhs == nullptr) return true;
		return lhs->vals[0] < rhs->vals[0];
		});
}
void split_node(Node23** node, Node23** r) {
	if (!(*node) || (*node)->size < 3) return;
	bool root = false;
	if (!((*node)->father)) {
		(*node)->father = new Node23;
		root = true;
	}
	insert_in_node(&((*node)->father), (*node)->vals[1]);

	Node23* left = new Node23;
	Node23* right = new Node23;
	Node23* father = (*node)->father;
	left->sons[0] = (*node)->sons[0];
	left->sons[1] = (*node)->sons[1];
	right->sons[0] = (*node)->sons[2];
	right->sons[1] = (*node)->sons[3];
	left->vals[0] = (*node)->vals[0];
	right->vals[0] = (*node)->vals[2];
	for (size_t i = 0; i < 4; i++) {
		if (left->sons[i])
			left->sons[i]->father = left;
		if (right->sons[i])
			right->sons[i]->father = right;
	}
	left->size = 1;
	right->size = 1;
	int i = 0;
	for (; (father->sons[i] != *node) && i < 4; i++);
	delete (*node);
	*node = nullptr;
	if (i < 4) father->sons[i] = nullptr;
	addson(&father, &left);
	addson(&father, &right);
	if (root) {
		*r = father;
		father->father = nullptr;
	}
	return split_node(&father, r);
}
void node23_insert(Node23** node, const string& val, Node23** r) {
	if (*node) {
		if (isleaf(*node)) {
			insert_in_node(node, val);
			split_node(node, r);
		}
		else if (val < (*node)->vals[0]) {
			return node23_insert(&((*node)->sons[0]), val, r);
		}
		else if (val < (*node)->vals[1] || (*node)->vals[1] == "") {
			return node23_insert(&((*node)->sons[1]), val, r);
		}
		else {
			return node23_insert(&((*node)->sons[2]), val, r);
		}
	}
	else {
		(*node) = new Node23;
		(*node)->size = 1;
		(*node)->vals[0] = val;
	}
}
void List23::Insert(const std::string& val) {
	size++;
	return node23_insert(&root, val, &root);
}
Node23* search(Node23* subtree, string val) {
	if (!subtree) return nullptr;

	if (subtree->vals[0] == val || subtree->vals[1] == val || subtree->vals[2] == val) return subtree;
	else if (val < subtree->vals[0]) return search(subtree->sons[0], val);
	else if (val < subtree->vals[1] || subtree->vals[1] == "") return search(subtree->sons[1], val);
	else return search(subtree->sons[2], val);
}
Node23* redistribute(Node23* node) {
	Node23* father = node->father;
	Node23* son_0 = father->sons[0];
	Node23* son_1 = father->sons[1];
	Node23* son_2 = father->sons[2];

	if ((father->size == 2) && (son_0->size < 2) && (son_1->size < 2) && (son_2->size < 2)) {
		if (son_0 == node) {
			father->sons[0] = father->sons[1];
			father->sons[1] = father->sons[2];
			father->sons[2] = nullptr;
			insert_in_node(&(father->sons[0]), father->vals[0]);
			father->sons[0]->sons[2] = father->sons[0]->sons[1];
			father->sons[0]->sons[1] = father->sons[0]->sons[0];

			if (node->sons[0] != nullptr) father->sons[0]->sons[0] = node->sons[0];
			else if (node->sons[1] != nullptr) father->sons[0]->sons[0] = node->sons[1];

			if (father->sons[0]->sons[0] != nullptr) father->sons[0]->sons[0]->father = father->sons[0];

			del_from_node(&father, father->vals[0]);
			delete son_0;
		}
		else if (son_1 == node) {
			insert_in_node(&son_0, father->vals[0]);
			del_from_node(&father, father->vals[0]);
			if (node->sons[0] != nullptr) son_0->sons[2] = node->sons[0];
			else if (node->sons[1] != nullptr) son_0->sons[2] = node->sons[1];

			if (son_0->sons[2] != nullptr) son_0->sons[2]->father = son_0;

			father->sons[1] = father->sons[2];
			father->sons[2] = nullptr;

			delete son_1;
		}
		else if (son_2 == node) {
			insert_in_node(&son_1, father->vals[1]);
			father->sons[2] = nullptr;
			del_from_node(&father, father->vals[1]);
			if (node->sons[0] != nullptr) son_1->sons[2] = node->sons[0];
			else if (node->sons[1] != nullptr) son_1->sons[2] = node->sons[1];

			if (son_1->sons[2] != nullptr)  son_1->sons[2]->father = son_1;

			delete son_2;
		}
	}
	else if ((father->size == 2) && ((son_0->size == 2) || (son_1->size == 2) || (son_2->size == 2))) {
		if (son_2 == node) {
			if (node->sons[0] != nullptr) {
				node->sons[1] = node->sons[0];
				node->sons[0] = nullptr;
			}

			insert_in_node(&node, father->vals[1]);
			if (son_1->size == 2) {
				father->vals[1] = son_1->vals[1];
				del_from_node(&son_1, son_1->vals[1]);
				node->sons[0] = son_1->sons[2];
				son_1->sons[2] = nullptr;
				if (node->sons[0] != nullptr) node->sons[0]->father = node;
			}
			else if (son_0->size == 2) {
				father->vals[1] = son_1->vals[0];
				node->sons[0] = son_1->sons[1];
				son_1->sons[1] = son_1->sons[0];
				if (node->sons[0] != nullptr) node->sons[0]->father = node;

				son_1->vals[0] = father->vals[0];
				father->vals[0] = son_0->vals[1];
				del_from_node(&son_0, son_0->vals[1]);
				son_1->sons[0] = son_0->sons[2];
				if (son_1->sons[0] != nullptr) son_1->sons[0]->father = son_1;
				son_0->sons[2] = nullptr;
			}
		}
		else if (son_1 == node) {
			if (son_2->size == 2) {
				if (node->sons[0] == nullptr) {
					node->sons[0] = node->sons[1];
					node->sons[1] = nullptr;
				}
				insert_in_node(&son_1, father->vals[1]);
				father->vals[1] = son_2->vals[0];
				del_from_node(&son_2, son_2->vals[0]);
				son_1->sons[1] = son_2->sons[0];
				if (son_1->sons[1] != nullptr) son_1->sons[1]->father = son_1;
				son_2->sons[0] = son_2->sons[1];
				son_2->sons[1] = son_2->sons[2];
				son_2->sons[2] = nullptr;
			}
			else if (son_0->size == 2) {
				if (node->sons[1] == nullptr) {
					node->sons[1] = node->sons[0];
					node->sons[0] = nullptr;
				}
				insert_in_node(&son_1, father->vals[0]);
				father->vals[0] = son_0->vals[1];
				del_from_node(&son_0, son_0->vals[1]);
				son_1->sons[0] = son_0->sons[2];
				if (son_1->sons[0] != nullptr) son_1->sons[0]->father = son_1;
				son_0->sons[2] = nullptr;
			}
		}
		else if (son_0 == node) {
			if (node->sons[0] == nullptr) {
				node->sons[0] = node->sons[1];
				node->sons[1] = nullptr;
			}
			insert_in_node(&son_0, father->vals[0]);
			if (son_1->size == 2) {
				father->vals[0] = son_1->vals[0];
				del_from_node(&son_1, son_1->vals[0]);
				son_0->sons[1] = son_1->sons[0];
				if (son_0->sons[1] != nullptr) son_0->sons[1]->father = son_0;
				son_1->sons[0] = son_1->sons[1];
				son_1->sons[1] = son_1->sons[2];
				son_1->sons[2] = nullptr;
			}
			else if (son_2->size == 2) {
				father->vals[0] = son_1->vals[0];
				son_1->vals[0] = father->vals[1];
				father->vals[1] = son_2->vals[0];
				del_from_node(&son_2, son_2->vals[0]);
				son_0->sons[1] = son_1->sons[0];
				if (son_0->sons[1] != nullptr) son_0->sons[1]->father = son_0;
				son_1->sons[0] = son_1->sons[1];
				son_1->sons[1] = son_2->sons[0];
				if (son_1->sons[1] != nullptr) son_1->sons[1]->father = son_1;
				son_2->sons[0] = son_2->sons[1];
				son_2->sons[1] = son_2->sons[2];
				son_2->sons[2] = nullptr;
			}
		}
	}
	else if (father->size == 1) {
		insert_in_node(&node, father->vals[0]);

		if (son_0 == node && son_1->size == 2) {
			father->vals[0] = son_1->vals[0];
			del_from_node(&son_1, son_1->vals[0]);

			if (node->sons[0] == nullptr) node->sons[0] = node->sons[1];

			node->sons[1] = son_1->sons[0];
			son_1->sons[0] = son_1->sons[1];
			son_1->sons[1] = son_1->sons[2];
			son_1->sons[2] = nullptr;
			if (node->sons[1] != nullptr) node->sons[1]->father = node;
		}
		else if (son_1 == node && son_0->size == 2) {
			father->vals[0] = son_0->vals[1];
			del_from_node(&son_0, son_0->vals[1]);

			if (node->sons[1] == nullptr) node->sons[1] = node->sons[0];

			node->sons[0] = son_0->sons[2];
			son_0->sons[2] = nullptr;
			if (node->sons[0] != nullptr) node->sons[0]->father = node;
		}
	}
	return father;
}
Node23* merge(Node23* node, Node23** r) {
	Node23* father = node->father;

	if (father->sons[0] == node) {
		insert_in_node(&(father->sons[1]), father->vals[0]);
		father->sons[1]->sons[2] = father->sons[1]->sons[1];
		father->sons[1]->sons[1] = father->sons[1]->sons[0];

		if (node->sons[0] != nullptr) father->sons[1]->sons[0] = node->sons[0];
		else if (node->sons[1] != nullptr) father->sons[1]->sons[0] = node->sons[1];

		if (father->sons[1]->sons[0] != nullptr) father->sons[1]->sons[0]->father = father->sons[1];

		del_from_node(&father, father->vals[0]);
		delete father->sons[0];
		father->sons[0] = nullptr;
	}
	else if (father->sons[1] == node) {
		insert_in_node(&(father->sons[0]), father->vals[0]);

		if (node->sons[0] != nullptr) father->sons[0]->sons[2] = node->sons[0];
		else if (node->sons[1] != nullptr) father->sons[0]->sons[2] = node->sons[1];

		if (father->sons[0]->sons[2] != nullptr) father->sons[0]->sons[2]->father = father->sons[0];

		del_from_node(&father, father->vals[0]);
		delete father->sons[1];
		father->sons[1] = nullptr;
	}

	if (father->father == nullptr) {
		Node23* tmp = nullptr;
		if (father->sons[0] != nullptr) tmp = father->sons[0];
		else tmp = father->sons[1];
		tmp->father = nullptr;
		delete father;
		*r = tmp;
		return tmp;
	}
	return father;
}
Node23* fix(Node23* node, Node23** r) {
	if (node->size == 0 && node->father == nullptr) { // Случай 0, когда удаляем единственный ключ в дереве
		delete node;
		return nullptr;
	}
	if (node->size > 0) { // Случай 1, когда вершина, в которой удалили ключ, имела два ключа
		if (node->father) return fix(node->father, r);
		else return node;
	}

	Node23* father = node->father;
	if (father->sons[0]->size == 2 || father->sons[1]->size == 2 || father->size == 2) node = redistribute(node); // Случай 2, когда достаточно перераспределить ключи в дереве
	else if (father->size == 2 && father->sons[2]->size == 2) node = redistribute(node); // Аналогично
	else node = merge(node, r); // Случай 3, когда нужно произвести склеивание и пройтись вверх по дереву как минимум на еще одну вершину

	return fix(node, r);
}
bool List23::Erase(const std::string& val) { // Удаление ключа k в 2-3-дереве с корнем p.
	Node23* del = search(root, val); // Ищем узел, где находится ключ k

	if (!del) return false;

	Node23* min = nullptr;
	if (del->vals[0] == val) min = del->sons[1]; // Ищем эквивалентный ключ
	else min = del->sons[2];

	while (min && min->sons[0]) min = min->sons[0];

	if (min) { // Меняем ключи местами
		std::swap((val == del->vals[0] ? del->vals[0] : del->vals[1]), min->vals[0]);
		del = min; // Перемещаем указатель на лист, т.к. min - всегда лист
	}

	del_from_node(&del, val); // И удаляем требуемый ключ из листа
	fix(del, &root); // Вызываем функцию для восстановления свойств дерева.
	size--;
	if (size == 0)
		root = nullptr;
	return true;
}
void print_node23(std::ostream& out, Node23* node) {
	if (node) {
		print_node23(out, node->sons[0]);
		out << node->vals[0] << std::endl;
		print_node23(out, node->sons[1]);
		if (node->vals[1] != "") {
			out << node->vals[1] << std::endl;
			print_node23(out, node->sons[2]);
		}
	}
}
void List23::Print(std::ostream& out) const {
	return print_node23(out, root);
}
bool List23::Find(const std::string& val) const {
	return bool(search(root, val));
}
void vec_from_node23(vector<string>& res, Node23* node, const string& first, const string& last) {
	if (node) {
		vec_from_node23(res, node->sons[0], first, last);
		res.push_back(node->vals[0]);
		vec_from_node23(res, node->sons[1], first, last);
		if (node->vals[1] != "") {
			res.push_back(node->vals[1]);
			vec_from_node23(res, node->sons[2], first, last);
		}
	}
}
vector<string> List23::Find(const string& first, const string& last) const {
	vector<string> res;
	vec_from_node23(res, root, first, last);
	return res;
}
void delete_all(Node23* node) {
	if (node) {
		delete_all(node->sons[0]);
		delete_all(node->sons[1]);
		delete_all(node->sons[2]);
		delete_all(node->sons[3]);
		delete node;
	}
}
List23::~List23() {
	delete_all(root);
}
void foo_for_each(Node23* node, void (*foo)(std::string&)) {
	if (node) {
		foo_for_each(node->sons[0], foo);
		foo(node->vals[0]);
		foo_for_each(node->sons[1], foo);
		if (node->vals[1] != "") {
			foo(node->vals[1]);
			foo_for_each(node->sons[2], foo);
		}
	}
}
void List23::ForEach(void (*foo)(std::string&)) {
	foo_for_each(root, foo);
}




string LinkedList::Type() const { return "LinkedList"; };
string ArrayList::Type() const { return "ArrayList"; };
string TreeList::Type() const { return "TreeList"; };
string AVLList::Type() const { return "AVLList"; };
string List23::Type() const { return "List23"; };