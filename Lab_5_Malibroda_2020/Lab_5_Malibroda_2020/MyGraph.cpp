#include "MyGraph.h"
#include <algorithm>
#include <set>

using std::string;
using std::ostream;
using std::set;
using std::vector;
using std::to_string;
using std::endl;
using std::cout;
using std::copy;
using std::min;

GraphExc::GraphExc(const string& message) : logic_error(message) {};

MyGraph::~MyGraph() {};

ostream& operator<<(ostream& out, const MyGraph& grph) {
	grph.Print(out);
	return out;
}

MatrixGraph::MatrixGraph(int n) : n{ n } {
	if (n < 0)
		throw GraphExc("(Constructor) Invalid number of vertexes: " + to_string(n));
	weights = new double* [n];
	matrix = new int* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new int[n] {0};
		weights[i] = new double[n] {0};
	}
}

MatrixGraph::MatrixGraph(int n, int m) : MatrixGraph{ n } {
	if (m < 0)
		throw GraphExc("(Constructor) Invalid number of edges: " + to_string(m));
	for (size_t k = 0; k < m; k++) {
		int i{ rand() % n }, j{ rand() % n };
		PushEdge(i, j);
	}
}

MatrixGraph::MatrixGraph(const MatrixGraph& cop) {
	*this = cop;
}

void MatrixGraph::PushEdge(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(PushEdge) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));

	matrix[i][j]++;
	m++;

	if (!orientation && i != j)
		matrix[j][i]++;

	SetWeight(i, j, 1);
}

void MatrixGraph::Print(ostream& out) const {
	out << "V={ ";
	for (size_t i = 0; i < n; i++)
		out << i << (i == n - 1 ? "" : ", ");
	out << " }" << endl;

	int printed_edges = 0;
	out << "E={ ";
	for (size_t i = 0; i < n; i++)
		for (size_t j = i; j < n; j++) {
			if (orientation) {
				if (matrix[i][j] > 0) {
					out << (matrix[i][j] == 1 ? "" : to_string(matrix[i][j]) + "x") << "(" << i << "->" << j << (printed_edges == m - matrix[i][j] ? ")" : "), ");
					printed_edges += matrix[i][j];
				}
				if (i != j && matrix[j][i] > 0) {
					out << (matrix[j][i] == 1 ? "" : to_string(matrix[j][i]) + "x") << "(" << j << "->" << i << (printed_edges == m - matrix[j][i] ? ")" : "), ");
					printed_edges += matrix[i][j];
				}
			}
			else {
				if (matrix[i][j] > 0) {
					out << (matrix[i][j] == 1 ? "" : to_string(matrix[i][j]) + "x") << "(" << i << "," << j << (printed_edges == m - matrix[i][j] ? ")" : "), ");
					printed_edges += matrix[i][j];
				}
			}
		}
	out << " }" << endl;
}

void MatrixGraph::SetOrientation(bool ortn) {
	if (orientation == ortn)
		return;

	orientation = ortn;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < i; j++) {
			matrix[i][j] = (orientation == true ? 0 : matrix[j][i]);
			weights[i][j] = (orientation == true ? 0 : weights[j][i]);
		}
}

void MatrixGraph::SetWeight(int i, int j, double weight) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(SetWeight) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));
	if (weight <= 0)
		throw GraphExc("(SetWeight) Invalid weight: " + to_string(weight));
	if (matrix[i][j] < 1)
		throw GraphExc("(SetWeight) Edge (" + to_string(i) + "," + to_string(j) + ") doesn`t exist");

	weights[i][j] = weight;

	if (!orientation)
		weights[j][i] = weight;
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph& arg) {
	for (size_t i = 0; i < n; i++) {
		if (matrix[i])
			delete[] matrix[i];
		if (weights[i])
			delete[]weights[i];
	}
	if (matrix)
		delete[] matrix;
	if (weights)
		delete[] weights;

	orientation = arg.orientation;
	n = arg.n;
	m = arg.m;
	matrix = new int* [n];
	weights = new double* [n];
	for (size_t i = 0; i < arg.n; i++) {
		matrix[i] = new int[n] {0};
		weights[i] = new double[n] {0};
		for (size_t j = 0; j < n; j++) {
			matrix[i][j] = arg.matrix[i][j];
			weights[i][j] = arg.weights[i][j];
		}
	}
	return *this;
}

LinkedGraph ToLinked(const MatrixGraph& arg) {
	LinkedGraph res(arg.n);
	res.SetOrientation(arg.orientation);
	for (size_t i = 0; i < arg.n; i++)
		for (size_t j = i; j < arg.n; j++) {
			if (arg.orientation) {
				for (size_t k = 0; k < arg.matrix[i][j]; k++) {}
				res.PushEdge(i, j);
				if (i != j)
					for (size_t k = 0; k < arg.matrix[j][i]; k++)
						res.PushEdge(j, i);
			}
			else {
				for (size_t k = 0; k < arg.matrix[i][j]; k++)
					res.PushEdge(i, j);
			}
			res.weights[i][j] = arg.weights[i][j];
			res.weights[j][i] = arg.weights[j][i];
		}
	return res;
}

MatrixGraph::~MatrixGraph() {
	for (size_t i = 0; i < n; i++) {
		if (matrix[i])
			delete[] matrix[i];
		if (weights[i])
			delete[] weights[i];
	}
	if (matrix)
		delete[] matrix;
	if (weights)
		delete[] weights;
}

double MatrixGraph::GetWeight(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(GetWeight) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));
	if (matrix[i][j] < 1)
		throw GraphExc("(GetWeight) Edge (" + to_string(i) + "," + to_string(j) + ") doesn`t exist");

	return weights[i][j];
}

void DSMatrixGraph(const MatrixGraph& arg, int i, bool* is_passed, int& res) {
	is_passed[i] = true;
	res++;
	for (size_t j = 0; j < arg.n; j++) {
		if (!is_passed[j] && arg.matrix[i][j] > 0)
			DSMatrixGraph(arg, j, is_passed, res);
	}
}

void MatrixGraph::DepthSearch() const {
	int res = 0;
	bool* is_passed = new bool[n] {0};
	for (size_t i = 0; i < n; i++) {
		if (!is_passed[i])
			DSMatrixGraph(*this, i, is_passed, res);
	}
	delete[] is_passed;
	cout << "Passed " << res << " vertexes" << endl;
}

bool MatrixGraph::Connectivity() const {
	int res = 0;
	bool* is_passed = new bool[n] {0};
	DSMatrixGraph(*this, 0, is_passed, res);
	delete[] is_passed;
	return res == n;
}

int MatrixGraph::Vertexes() const {
	return n;
}

double** MatrixGraph::FloydAllLenghts() const {
	double** lenghts = new double* [n];
	for (size_t i = 0; i < n; i++) {
		lenghts[i] = new double[n];
		copy(&(weights[i][0]), &(weights[i][n]), &(lenghts[i][0]));
	}

	for (size_t k = 0; k < n; k++)
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++) {
				if (lenghts[i][j] <= 0) lenghts[i][j] = DBL_MAX;
				if (lenghts[i][k] <= 0) lenghts[i][k] = DBL_MAX;
				if (lenghts[k][j] <= 0) lenghts[k][j] = DBL_MAX;
				lenghts[i][j] = min(lenghts[i][j], lenghts[i][k] + lenghts[k][j]);
			}

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++) {
			if (lenghts[i][j] >= DBL_MAX / 2)
				lenghts[i][j] = 0;
		}

	return lenghts;
}

double* MatrixGraph::FloydOneVertex(int i) const {
	if (i < 0 || i >= n)
		throw GraphExc("(FloydOneVertex) Invalid index of vertex: i = " + to_string(i));

	double** D = FloydAllLenghts();
	double* res = D[i];
	D[i] = nullptr;
	for (size_t i = 0; i < n; i++) {
		if (D[i])
			delete[] D[i];
	}
	if (D)
		delete[] D;
	return res;
}

double MatrixGraph::FloydTwoVertexes(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(FloydTwoVertexes) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));

	double** D = FloydAllLenghts();
	double res = D[i][j];
	for (size_t i = 0; i < n; i++) {
		if (D[i])
			delete[] D[i];
	}
	if (D)
		delete[] D;
	return res;
}

void TopSort(const MatrixGraph& arg, int* vrtxs, vector<int>& res, int cur) {
	if (vrtxs[cur] == 1)
		return;
	else if (vrtxs[cur] == -1)
		throw GraphExc("(TopSort) Topologic sort isn't possible: founded cycle");
	else if (vrtxs[cur] == 0) {
		vrtxs[cur] = -1;
		for (size_t i = 0; i < arg.n; i++)
			if (arg.matrix[cur][i] > 0)
				TopSort(arg, vrtxs, res, i);
		vrtxs[cur] = 1;
		res.insert(res.begin(), cur);
	}
}

vector<int> MatrixGraph::SortDeepSearch() const {
	if (!orientation)
		throw GraphExc("(SortDeepSearch) Topologic sort isn't possible: graph isn't orientatied");

	int* vrtxs = new int[n] {0};
	vector<int> res;
	for (size_t cur = 0; cur < n; cur++)
		TopSort(*this, vrtxs, res, cur);
	delete[] vrtxs;
	return res;
}

void ToTr(const MatrixGraph& inp, MatrixGraph& outp, int cur, bool* isin, int& count) {
	isin[cur] = true;
	count++;
	for (size_t j = 0; j < inp.n; j++) {
		if (!isin[j] && inp.matrix[cur][j] > 0) {
			outp.PushEdge(cur, j);
			outp.weights[cur][j] = inp.weights[cur][j];
			ToTr(inp, outp, j, isin, count);
		}
	}

}

MatrixGraph MatrixGraph::ToTree() const {
	MatrixGraph res(n);
	bool* isin = new bool[n] {0};
	int count = 0;
	ToTr(*this, res, 0, isin, count);
	if (count != n)
		throw GraphExc("(ToTree) Tree isn't possible: connectivity is false");
	delete[] isin;
	return res;
}

double MatrixGraph::WeightsSum() const {
	double res = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = i; j < n; j++) {
			res += weights[i][j];

			if (orientation && i != j)
				res += weights[i][j];
		}
	return res;
}

MatrixGraph MatrixGraph::MinTree() const {
	if (Connectivity() == false)
		throw GraphExc("(MinTree) Tree isn't possible: connectivity is false");

	MatrixGraph res(n);
	set<int> V;
	set<int> U = { 0 };
	for (size_t i = 1; i < n; i++)
		V.insert(i);

	while (V.size() > 0) {
		int min_i{ 0 }, min_j{ 0 };
		double min_w = DBL_MAX;
		for (int i : U)
			for (int j : V) {
				if (matrix[i][j] && min_w > weights[i][j]) {
					min_w = weights[i][j];
					min_i = i;
					min_j = j;
				}
			}
		res.PushEdge(min_i, min_j);
		res.SetWeight(min_i, min_j, weights[min_i][min_j]);
		U.insert(min_j);
		V.erase(min_j);
	}
	return res;
}

string MatrixGraph::Type() const {
	return "MatrixGraph";
}



LinkedGraph::LinkedGraph(int n) {
	if (n < 0)
		throw GraphExc("(Constructor) Invalid number of vertexes: " + to_string(n));

	link_struct = new vector<int>[n];
	this->n = n;

	weights = new double* [n];
	for (size_t i = 0; i < n; i++) {
		weights[i] = new double[n] {0};
	}
}

LinkedGraph::LinkedGraph(int n, int m) : LinkedGraph{ n } {
	if (m < 0)
		throw GraphExc("(Constructor) Invalid number of edges: " + to_string(m));
	for (size_t k = 0; k < m; k++) {
		int i{ rand() % n }, j{ rand() % n };
		PushEdge(i, j);
	}
}

LinkedGraph::LinkedGraph(const LinkedGraph& cop) {
	*this = cop;
}

void LinkedGraph::PushEdge(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(PushEdge) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));

	vector<int>::iterator it1 = lower_bound(begin(link_struct[i]), end(link_struct[i]), j);
	link_struct[i].insert(it1, j);
	m++;

	if (!orientation && i != j) {
		vector<int>::iterator it2 = lower_bound(begin(link_struct[j]), end(link_struct[j]), i);
		link_struct[j].insert(it2, i);
	}

	SetWeight(i, j, 1);
}

void LinkedGraph::Print(ostream& out) const {
	out << "V={ ";
	for (size_t i = 0; i < n; i++)
		out << i << (i == n - 1 ? "" : ", ");
	out << " }" << endl;

	int printed_edges{ 0 };
	out << "E={ ";
	for (size_t i = 0; i < n; i++)
		for (size_t j = i; j < n; j++) {
			if (orientation) {
				if (IsEdge(i, j) > 0) {
					out << (IsEdge(i, j) == 1 ? "" : to_string(IsEdge(i, j)) + "x") << "(" << i << "->" << j << (printed_edges == m - IsEdge(i, j) ? ")" : "), ");
					printed_edges += IsEdge(i, j);
				}
				if (i != j && IsEdge(j, i) > 0) {
					out << (IsEdge(j, i) == 1 ? "" : to_string(IsEdge(j, i)) + "x") << "(" << j << "->" << i << (printed_edges == m - IsEdge(j, i) ? ")" : "), ");
					printed_edges += IsEdge(i, j);
				}
			}
			else {
				if (IsEdge(i, j) > 0) {
					out << (IsEdge(i, j) == 1 ? "" : to_string(IsEdge(i, j)) + "x") << "(" << i << "," << j << (printed_edges == m - IsEdge(i, j) ? ")" : "), ");
					printed_edges += IsEdge(i, j);
				}
			}
		}
	out << " }" << endl;
}

int LinkedGraph::IsEdge(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(IsEdge) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));
	int res = 0;
	vector<int>::iterator it = find(begin(link_struct[i]), end(link_struct[i]), j);
	while (it != link_struct[i].end()) {
		res++;
		it = find(it + 1, end(link_struct[i]), j);
	}
	return res;
}

LinkedGraph& LinkedGraph::operator=(const LinkedGraph& arg) {
	delete[] link_struct;
	for (size_t i = 0; i < n; i++) {
		if (weights[i])
			delete[] weights[i];
	}
	if (weights)
		delete[] weights;

	n = arg.n;
	m = arg.m;
	link_struct = new vector<int>[n];
	weights = new double* [n];
	for (size_t i = 0; i < n; i++) {
		link_struct[i] = arg.link_struct[i];
		weights[i] = new double[n];
		copy(&(arg.weights[i][0]), &(arg.weights[i][n]), &(weights[i][0]));
	}
	return *this;
}

MatrixGraph ToMatrix(const LinkedGraph& arg) {
	MatrixGraph res(arg.n);
	res.SetOrientation(arg.orientation);
	for (size_t i = 0; i < arg.n; i++)
		for (size_t j = i; j < arg.n; j++) {
			if (arg.orientation) {
				for (size_t k = 0; k < arg.IsEdge(i, j); k++)
					res.PushEdge(i, j);
				if (i != j)
					for (size_t k = 0; k < arg.IsEdge(j, i); k++)
						res.PushEdge(j, i);
			}
			else {
				for (size_t k = 0; k < arg.IsEdge(i, j); k++)
					res.PushEdge(i, j);
			}
			res.weights[i][j] = arg.weights[i][j];
			res.weights[j][i] = arg.weights[j][i];
		}
	return res;
}

void LinkedGraph::SetOrientation(bool ortn) {
	if (orientation == ortn)
		return;

	orientation = ortn;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < i; j++) {
			if (!orientation) {
				int a = IsEdge(i, j), b = IsEdge(j, i);
				for (size_t k = 0; k < a; k++) {
					vector<int>::iterator it1 = lower_bound(begin(link_struct[j]), end(link_struct[j]), i);
					link_struct[j].insert(it1, i);
				}
				for (size_t k = 0; k < b; k++) {
					vector<int>::iterator it1 = lower_bound(begin(link_struct[i]), end(link_struct[i]), j);
					link_struct[i].insert(it1, j);
				}
			}
			else
				link_struct[i].erase(find(begin(link_struct[i]), end(link_struct[i]), j), find(begin(link_struct[i]), end(link_struct[i]), j) + IsEdge(i, j));

			weights[i][j] = (orientation == true ? 0 : weights[j][i]);
		}
}

void LinkedGraph::SetWeight(int i, int j, double weight) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(SetWeight) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));
	if (weight <= 0)
		throw GraphExc("(SetWeight) Invalid weight: " + to_string(weight));
	if (IsEdge(i, j) < 1)
		throw GraphExc("(SetWeight) Edge (" + to_string(i) + "," + to_string(j) + ") doesn`t exist");

	weights[i][j] = weight;

	if (!orientation)
		weights[j][i] = weight;
}

LinkedGraph::~LinkedGraph() {
	delete[] link_struct;
	for (size_t i = 0; i < n; i++) {
		if (weights[i])
			delete[] weights[i];
	}
	if (weights)
		delete[] weights;
}

double LinkedGraph::GetWeight(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(GetWeight) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));
	if (IsEdge(i, j) < 1)
		throw GraphExc("(GetWeight) Edge (" + to_string(i) + "," + to_string(j) + ") doesn`t exist");

	return weights[i][j];
}

void DSLinkedGraph(const LinkedGraph& arg, int i, bool* is_passed, int& res) {
	is_passed[i] = true;
	res++;
	for (size_t j = 0; j < arg.link_struct[i].size(); j++) {
		if (!is_passed[arg.link_struct[i][j]])
			DSLinkedGraph(arg, arg.link_struct[i][j], is_passed, res);
	}
}

void LinkedGraph::DepthSearch() const {
	int res = 0;
	bool* is_passed = new bool[n] {0};
	for (size_t i = 0; i < n; i++) {
		if (!is_passed[i])
			DSLinkedGraph(*this, i, is_passed, res);
	}
	delete[] is_passed;
	cout << "Passed " << res << " vertexes" << endl;
}

bool LinkedGraph::Connectivity() const {
	int res = 0;
	bool* is_passed = new bool[n] {0};
	DSLinkedGraph(*this, 0, is_passed, res);
	delete[] is_passed;
	return res == n;
}

int LinkedGraph::Vertexes() const {
	return n;
}

double** LinkedGraph::FloydAllLenghts() const {
	double** lenghts = new double* [n];
	for (size_t i = 0; i < n; i++) {
		lenghts[i] = new double[n];
		copy(&(weights[i][0]), &(weights[i][n]), &(lenghts[i][0]));
	}

	for (size_t k = 0; k < n; k++)
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++) {
				if (lenghts[i][j] <= 0) lenghts[i][j] = DBL_MAX;
				if (lenghts[i][k] <= 0) lenghts[i][k] = DBL_MAX;
				if (lenghts[k][j] <= 0) lenghts[k][j] = DBL_MAX;
				lenghts[i][j] = min(lenghts[i][j], lenghts[i][k] + lenghts[k][j]);
			}

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++) {
			if (lenghts[i][j] >= DBL_MAX / 2)
				lenghts[i][j] = 0;
		}

	return lenghts;
}

double* LinkedGraph::FloydOneVertex(int i) const {
	if (i < 0 || i >= n)
		throw GraphExc("(FloydOneVertex) Invalid index of vertex: i = " + to_string(i));

	double** D = FloydAllLenghts();
	double* res = D[i];
	D[i] = nullptr;
	for (size_t i = 0; i < n; i++) {
		if (D[i])
			delete[] D[i];
	}
	if (D)
		delete[] D;
	return res;
}

double LinkedGraph::FloydTwoVertexes(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n)
		throw GraphExc("(FloydTwoVertexes) Invalid indexes of vertexes: i = " + to_string(i) + ", j = " + to_string(j));

	double** D = FloydAllLenghts();
	double res = D[i][j];
	for (size_t i = 0; i < n; i++) {
		if (D[i])
			delete[] D[i];
	}
	if (D)
		delete[] D;
	return res;
}

void TopSort(const LinkedGraph& arg, int* vrtxs, vector<int>& res, int cur) {
	if (vrtxs[cur] == 1)
		return;
	else if (vrtxs[cur] == -1)
		throw GraphExc("(TopSort) Topologic sort isn't possible: founded cycle");
	else if (vrtxs[cur] == 0) {
		vrtxs[cur] = -1;
		for (size_t i = 0; i < arg.link_struct[cur].size(); i++)
			TopSort(arg, vrtxs, res, arg.link_struct[cur][i]);
		vrtxs[cur] = 1;
		res.insert(res.begin(), cur);
	}
}

vector<int> LinkedGraph::SortDeepSearch() const {
	if (!orientation)
		throw GraphExc("(SortDeepSearch) Topologic sort isn't possible: graph isn't orientatied");

	int* vrtxs = new int[n] {0};
	vector<int> res;
	for (size_t cur = 0; cur < n; cur++)
		TopSort(*this, vrtxs, res, cur);
	delete[] vrtxs;
	return res;
}

void ToTr(const LinkedGraph& inp, LinkedGraph& outp, int cur, bool* isin, int& count) {
	isin[cur] = true;
	count++;
	for (size_t j = 0; j < inp.link_struct[cur].size(); j++) {
		if (!isin[inp.link_struct[cur][j]]) {
			outp.PushEdge(cur, inp.link_struct[cur][j]);
			outp.weights[cur][inp.link_struct[cur][j]] = inp.weights[cur][inp.link_struct[cur][j]];
			ToTr(inp, outp, inp.link_struct[cur][j], isin, count);
		}
	}
}

LinkedGraph LinkedGraph::ToTree() const {
	LinkedGraph res(n);
	bool* isin = new bool[n] {0};
	int count = 0;
	ToTr(*this, res, 0, isin, count);
	if (count != n)
		throw GraphExc("(ToTree) Tree isn't possible: connectivity is false");
	delete[] isin;
	return res;
}

double LinkedGraph::WeightsSum() const {
	double res = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = i; j < n; j++) {
			res += weights[i][j];

			if (orientation && i != j)
				res += weights[i][j];
		}
	return res;
}

LinkedGraph LinkedGraph::MinTree() const {
	if (Connectivity() == false)
		throw GraphExc("(MinTree) Tree isn't possible: connectivity is false");

	LinkedGraph res(n);
	set<int> V;
	set<int> U = { 0 };
	for (size_t i = 1; i < n; i++)
		V.insert(i);

	while (V.size() > 0) {
		int min_i{ 0 }, min_j{ 0 };
		double min_w = DBL_MAX;
		for (int i : U)
			for (int j : V) {
				if (IsEdge(i, j) && min_w > weights[i][j]) {
					min_w = weights[i][j];
					min_i = i;
					min_j = j;
				}
			}
		res.PushEdge(min_i, min_j);
		res.weights[min_i][min_j] = weights[min_i][min_j];
		U.insert(min_j);
		V.erase(min_j);
	}
	return res;
}

string LinkedGraph::Type() const {
	return "LinkedGraph";
}
