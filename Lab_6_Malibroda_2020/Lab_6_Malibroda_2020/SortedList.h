#pragma once
#include <iostream>
#include <vector>
#include <string>

std::string randstr();

class SortedList {
protected:
	int size = 0;
public:
	virtual void Insert(const std::string& val) = 0;
	virtual void Random(int N);
	virtual void Print(std::ostream& out = std::cout) const = 0;
	virtual void ForEach(void (*foo)(std::string&)) = 0;
	virtual bool Erase(const std::string& val) = 0;
	int Size() const;
	virtual bool Find(const std::string& val) const = 0;
	virtual std::vector<std::string> Find(const std::string& first, const std::string& last) const = 0;
	virtual ~SortedList() = 0;
	virtual std::string Type() const = 0;
};

std::ostream& operator<<(std::ostream& out, const SortedList& list);

struct Node {
	std::string val;
	Node* next = nullptr;
};

class LinkedList : public SortedList {
private:
	Node* head = nullptr;
public:
	LinkedList();
	LinkedList(int N);
	void Insert(const std::string& val) override;
	void Print(std::ostream& out = std::cout) const override;
	void ForEach(void (*foo)(std::string&)) override;
	bool Erase(const std::string& val) override;
	bool Find(const std::string& val) const override;
	std::vector<std::string> Find(const std::string& first, const std::string& last) const override;
	~LinkedList() override;
	std::string Type() const override;
};


class ArrayList : public SortedList {
private:
	std::string* arr = nullptr;
	int max_size = 32;
	void upsize();
	void downsize();
public:
	ArrayList();
	ArrayList(int N);
	void Insert(const std::string& val) override;
	void Print(std::ostream& out = std::cout) const override;
	void ForEach(void (*foo)(std::string&)) override;
	bool Erase(const std::string& val) override;
	bool Find(const std::string& val) const override;
	std::vector<std::string> Find(const std::string& first, const std::string& last) const override;
	~ArrayList() override;
	std::string Type() const override;
};

struct TreeNode {
	std::string val;
	TreeNode* father = nullptr;
	TreeNode* lson = nullptr;
	TreeNode* rson = nullptr;
	int height = 0;
};

class TreeList : public SortedList {
protected:
	TreeNode* root = nullptr;
	virtual bool erase_val_subtr(TreeNode* node, const std::string& val);
public:
	TreeList();
	TreeList(int N);
	void Insert(const std::string& val) override;
	void Print(std::ostream& out = std::cout) const override;
	void ForEach(void (*foo)(std::string&)) override;
	bool Erase(const std::string& val) override;
	bool Find(const std::string& val) const override;
	std::vector<std::string> Find(const std::string& first, const std::string& last) const override;
	~TreeList() override;
	std::string Type() const override;
};

class AVLList : public TreeList {
public:
	void Insert(const std::string& val) override;
	bool Erase(const std::string& val) override;
private:
	std::string Type() const override;
};


struct Node23 {
	std::string vals[3];
	int size = 0;
	int scount = 0;
	Node23* father = nullptr;
	Node23* sons[4] { nullptr , nullptr, nullptr, nullptr};
};


class List23 : public SortedList {
private:
	Node23* root = nullptr;
public:
	List23();
	List23(int N);
	void Insert(const std::string& val) override;
	void Print(std::ostream& out = std::cout) const override;
	void ForEach(void (*foo)(std::string&)) override;
	bool Erase(const std::string& val) override;
	bool Find(const std::string& val) const override;
	std::vector<std::string> Find(const std::string& first, const std::string& last) const override;
	~List23() override;
	std::string Type() const override;
};