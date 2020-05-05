#pragma once

#include <iostream>
#include <string>
#include <vector>
//using namespace std;

class GraphExc : public std::logic_error {
public:
	explicit GraphExc(const std::string& message);
};

class MyGraph
{
public:
	virtual void Print(std::ostream& out = std::cout) const = 0;
	virtual void PushEdge(int i, int j) = 0;
	virtual void SetOrientation(bool ortn) = 0;
	virtual void SetWeight(int i, int j, double weight) = 0;
	virtual void DepthSearch() const = 0;
	virtual bool Connectivity() const = 0;
	virtual int Vertexes() const = 0;
	virtual double GetWeight(int i, int j) const = 0;
	virtual double WeightsSum() const = 0;
	virtual double FloydTwoVertexes(int i, int j) const = 0;
	virtual double* FloydOneVertex(int i) const = 0;
	virtual double** FloydAllLenghts() const = 0;
	virtual std::vector<int> SortDeepSearch() const = 0;
	virtual std::string Type() const = 0;
	virtual ~MyGraph() = 0;
};

std::ostream& operator<<(std::ostream& out, const MyGraph& grph);

class LinkedGraph;

class MatrixGraph :public MyGraph
{
private:

	int** matrix = nullptr;
	int n = 0;
	int m = 0;
	bool orientation = false;
	double** weights = nullptr;

public:

	MatrixGraph(int n);
	MatrixGraph(int n, int m);
	MatrixGraph(const MatrixGraph& cop);
	void PushEdge(int i, int j) override;
	void Print(std::ostream& out = std::cout) const	override;
	void SetOrientation(bool ortn) override;
	void SetWeight(int i, int j, double weight) override;
	void DepthSearch() const override;
	bool Connectivity() const override;
	int Vertexes() const override;
	double GetWeight(int i, int j) const override;
	double WeightsSum() const override;
	double FloydTwoVertexes(int i, int j) const override;
	double* FloydOneVertex(int i) const override;
	double** FloydAllLenghts() const override;
	MatrixGraph ToTree() const;
	MatrixGraph MinTree() const;
	MatrixGraph& operator=(const MatrixGraph& arg);
	std::vector<int> SortDeepSearch() const override;
	std::string Type() const override;
	~MatrixGraph()	override;
	friend void ToTr(const MatrixGraph& inp, MatrixGraph& outp, int cur, bool* isin, int& count);
	friend void TopSort(const MatrixGraph& arg, int* vrtxs, std::vector<int>& res, int cur);
	friend void DSMatrixGraph(const MatrixGraph& arg, int i, bool* is_passed, int& res);
	friend MatrixGraph ToMatrix(const LinkedGraph& arg);
	friend LinkedGraph ToLinked(const MatrixGraph& arg);
};

class LinkedGraph :public MyGraph
{
private:
	std::vector<int>* link_struct = nullptr;
	int n = 0;
	int m = 0;
	bool orientation = false;
	double** weights = nullptr;
public:
	LinkedGraph(int n);
	LinkedGraph(int n, int m);
	LinkedGraph(const LinkedGraph& cop);
	void PushEdge(int i, int j) override;
	void Print(std::ostream& out = std::cout) const	override;
	void SetOrientation(bool ortn) override;
	void SetWeight(int i, int j, double weight) override;
	void DepthSearch() const override;
	bool Connectivity() const override;
	int IsEdge(int i, int j) const;
	double GetWeight(int i, int j) const override;
	double WeightsSum() const override;
	double FloydTwoVertexes(int i, int j) const override;
	double* FloydOneVertex(int i) const override;
	double** FloydAllLenghts() const override;
	int Vertexes() const override;
	std::vector<int> SortDeepSearch() const override;
	std::string Type() const override;
	LinkedGraph ToTree() const;
	LinkedGraph MinTree() const;
	LinkedGraph& operator=(const LinkedGraph& arg);
	~LinkedGraph()	override;
	friend void DSLinkedGraph(const LinkedGraph& arg, int i, bool* is_passed, int& res);
	friend void ToTr(const LinkedGraph& inp, LinkedGraph& outp, int cur, bool* isin, int& count);
	friend LinkedGraph ToLinked(const MatrixGraph& arg);
	friend MatrixGraph ToMatrix(const LinkedGraph& arg);
	friend void TopSort(const LinkedGraph& arg, int* vrtxs, std::vector<int>& res, int cur);
};