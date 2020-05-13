#include "MyGraph.h"
#include "interface.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>

using std::istream;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::exception;
using std::setw;
using std::vector;
using std::setprecision;

template<class T>
bool get_data(T& val, istream& in)
{
	in >> val;
	if (in.fail()) {
		return false;
	}
	return true;
}

void link_bench(int N) {
	try {
		LinkedGraph gr(N, N);
		try {
			gr.DepthSearch();
		}
		catch (...) {}
		try {
			double** d = gr.FloydAllLenghts();
			delete d;
		}
		catch (...) {}
		try {
			gr.SortDeepSearch();
		}
		catch (...) {}
		try {
			gr.ToTree();
		}
		catch (...) {}
		try {
			gr.MinTree();
		}
		catch (...) {}
	}
	catch (...) {}
}

void matr_bench(int N) {
	try {
		MatrixGraph gr(N, N);
		try {
			gr.DepthSearch();
		}
		catch (...) {}
		try {
			double** d = gr.FloydAllLenghts();
			delete d;
		}
		catch (...) {}
		try {
			gr.SortDeepSearch();
		}
		catch (...) {}
		try {
			gr.ToTree();
		}
		catch (...) {}
		try {
			gr.MinTree();
		}
		catch (...) {}
	}
	catch (...) {}
}

void benchmark() {
	ofstream bench;
	bench.open("bench.txt");
	int N{ 10 }, d{ 10 };
	int matr_time{ 0 }, link_time{ 0 };
	std::chrono::steady_clock::time_point start, end;

	bench << "Time in milliseconds" << endl;
	cout << "Time in milliseconds" << endl;
	bench << setw(10) << "Count" << setw(10) << "Matrix" << setw(10) << "Linked" << endl;
	cout << setw(10) << "Count" << setw(10) << "Matrix" << setw(10) << "Linked" << endl;

	while (matr_time < 10000 || link_time < 10000) {

		start = std::chrono::steady_clock::now();
		matr_bench(N);
		end = std::chrono::steady_clock::now();
		matr_time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

		start = std::chrono::steady_clock::now();
		link_bench(N);
		end = std::chrono::steady_clock::now();
		link_time = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();

		bench << setw(10) << N << setw(10) << matr_time << setw(10) << link_time << endl;
		cout << setw(10) << N << setw(10) << matr_time << setw(10) << link_time << endl;

		if (matr_time < 1000 || link_time < 1000) {
			N *= 2;
			d = N;
		}
		else {
			N += d;
		}
	}
	bench.close();
}

void main_menu(istream& in) {
	cout << "Print 'help' for commands list" << endl << endl;
	string cmd, line;
	MyGraph* graph = nullptr;
	stringstream ss;
	while (true) {
		cmd = "";
		getline(in, line);
		ss.clear();
		ss.str(line);
		ss >> cmd;
		if (cmd == "help") {
			cout << "========================== COMMAND LIST ===========================" << endl;
			cout << "'add N' --- Save empty graph with N vertexes" << endl;
			cout << "'add N M' --- Save random graph with N vertexes and M edges" << endl;
			cout << "'del' --- Delete current saved graph" << endl;
			cout << "'push i j' --- Push edge from vertex i to vertex j" << endl;
			cout << "'print' --- Print saved graph" << endl;
			cout << "'type' --- Print type of saved graph" << endl;
			cout << "'swap' --- Change type of saved graph" << endl;
			cout << "'orient b' --- Change orientation of saved graph to b" << endl;
			cout << "'setw i j w' --- Set weight of edge (i, j) = w" << endl;
			cout << "'getw i j' --- Get weight of edge (i, j)" << endl;
			cout << "'con' --- Print connectivity of saved graph" << endl;
			cout << "'minlen' --- Print all min lenghts in saved graph" << endl;
			cout << "'minlen i' --- Print all min lenghts with vertex i" << endl;
			cout << "'minlen i j' --- Print min lenght from i to j" << endl;
			cout << "'tops' --- Print vertexes in topologic sorted order" << endl;
			cout << "'tree' --- Print spanning tree of saved graph and it's weight" << endl;
			cout << "'mintree' --- Print min spanning tree of saved graph and it's weight" << endl;
			cout << "'sum' --- Print summary weight of saved graph" << endl;
			cout << "'demo' --- Launch demonstration mode" << endl;
			cout << "'bench' --- Launch benchmark mode" << endl;
			cout << "'exit' --- Close programm" << endl;
			cout << "====================================================================" << endl << endl;
		}
		else if (cmd == "add") {
			int N, M;
			if (!get_data(N, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (!ss.eof()) {
				if (!get_data(M, ss)) {
					cout << "Invalid input" << endl << endl;
					continue;
				}
				if (graph) {
					cout << "You already have saved graph, delete it if you want to add new one" << endl << endl;
					continue;
				}
				else {
					try {
						graph = new MatrixGraph(N, M);
						cout << "Successfuly saved graph with " << N << " vertexes and " << M << " edges" << endl << endl;
						continue;
					}
					catch (const exception& e) {
						cout << e.what() << endl << endl;
						delete graph;
						graph = nullptr;
						continue;
					}
				}
			}
			if (graph) {
				cout << "You already have saved graph, delete it if you want to add new one" << endl << endl;
				continue;
			}
			else {
				try {
					graph = new MatrixGraph(N);
					cout << "Successfuly saved empty graph with " << N << " vertexes" << endl << endl;
					continue;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
					delete graph;
					continue;
				}
			}
		}
		else if (cmd == "del") {
			if (graph) {
				delete graph;
				graph = nullptr;
				cout << "Graph successfuly deleted" << endl << endl;
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "push") {
			int i, j;
			if (!(get_data(i, ss) && get_data(j, ss))) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (graph) {
				try {
					graph->PushEdge(i, j);
					cout << "Successfuly pushed edge (" << i << ", " << j << ")" << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "print") {
			if (graph) {
				graph->Print();
				cout << endl;
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "type") {
			if (graph) {
				cout << graph->Type() << endl << endl;
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "swap") {
			if (graph) {
				try {
					string type = graph->Type();
					if (type == "LinkedGraph") {
						MatrixGraph* tmp = new MatrixGraph(ToMatrix(*((LinkedGraph*)graph)));
						delete graph;
						graph = tmp;
						tmp = nullptr;
					}
					else {
						LinkedGraph* tmp = new LinkedGraph(ToLinked(*((MatrixGraph*)graph)));
						delete graph;
						graph = tmp;
						tmp = nullptr;
					}
					cout << "Successfuly swaped from " << type << " to " << graph->Type() << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
					delete graph;
					graph = nullptr;
					continue;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "orient") {
			bool ornt;
			if (!get_data(ornt, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (graph) {
				graph->SetOrientation(ornt);
				cout << "Orientation of graph is " << (ornt ? "true" : "false") << endl << endl;
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "setw") {
			int i, j;
			double w;
			if (!(get_data(i, ss) && get_data(j, ss) && get_data(w, ss))) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (graph) {
				try {
					graph->SetWeight(i, j, w);
					cout << "Successfuly: weight of (" << i << ", " << j << ") = " << w << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "getw") {
			int i, j;
			if (!(get_data(i, ss) && get_data(j, ss))) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (graph) {
				try {
					cout << "Weight of (" << i << ", " << j << ") = " << graph->GetWeight(i, j) << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "con") {
			if (graph) {
				cout << "Connectivity of graph is " << (graph->Connectivity() ? "true" : "false") << endl << endl;
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "minlen") {
			if (!graph) {
				cout << "You haven't saved graph" << endl << endl;
				continue;
			}
			int i, j;
			if (!ss.eof()) {
				try {
					if (!get_data(i, ss)) {
						cout << "Invalid input" << endl << endl;
						continue;
					}
					if (!ss.eof()) {
						if (!get_data(j, ss)) {
							cout << "Invalid input" << endl << endl;
							continue;
						}
						cout << "Min lenght from " << i << " to " << j << ": " << graph->FloydTwoVertexes(i, j) << endl << endl;
					}
					else {
						double* vec = graph->FloydOneVertex(i);
						cout << "All min lenghts with vertex " << i << ":" << endl;
						for (size_t i = 0; i < graph->Vertexes(); i++) {
							cout << setprecision(2) << setw(5) << vec[i] << '|';
						}
						cout << endl << endl;
						delete[] vec;
					}
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
					continue;
				}
			}
			else {
				double** mat = graph->FloydAllLenghts();
				cout << "All min lenghts in graph:" << endl;
				for (size_t i = 0; i < graph->Vertexes(); i++) {
					for (size_t j = 0; j < graph->Vertexes(); j++) {
						cout << setprecision(2) << setw(5) << mat[i][j] << '|';
					}
					cout << endl;
					delete[] mat[i];
				}
				cout << endl;
				delete[] mat;
			}
		}
		else if (cmd == "tops") {
			if (graph) {
				try {
					vector<int> vec = graph->SortDeepSearch();
					cout << "Vertexes in sorted order: ";
					for (int vert : vec) {
						cout << vert << ' ';
					}
					cout << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "tree") {
			if (graph) {
				try {
					if (graph->Type() == "LinkedGraph") {
						LinkedGraph tmp = ((LinkedGraph*)(graph))->ToTree();
						tmp.Print();
						cout << "Summary weight of tree: " << tmp.WeightsSum() << endl << endl;
					}
					else {
						MatrixGraph tmp = ((MatrixGraph*)(graph))->ToTree();
						tmp.Print();
						cout << "Summary weight of tree: " << tmp.WeightsSum() << endl << endl;
					}
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "mintree") {
			if (graph) {
				try {
					if (graph->Type() == "LinkedGraph") {
						LinkedGraph tmp = ((LinkedGraph*)(graph))->MinTree();
						tmp.Print();
						cout << "Summary weight of tree: " << tmp.WeightsSum() << endl << endl;
					}
					else {
						MatrixGraph tmp = ((MatrixGraph*)(graph))->MinTree();
						tmp.Print();
						cout << "Summary weight of tree: " << tmp.WeightsSum() << endl << endl;
					}
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "sum") {
			if (graph) {
				try {
					cout << "Summary weight of graph: " << graph->WeightsSum() << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved graph" << endl << endl;
			}
		}
		else if (cmd == "exit") {
			if (graph)
				delete graph;
			break;
		}
		else if (cmd == "demo") {
			ifstream demo;
			demo.open("demo.txt");
			main_menu(demo);
			demo.close();
		}
		else if (cmd == "bench") {
			cout << "Benchmark started, wait a few seconds..." << endl;
			benchmark();
			cout << "Benchmark ended" << endl << endl;
		}
		else if (cmd != "") {
			cout << "'" << cmd << "' is not command, print 'help' for commands list" << endl << endl;
		}
	}
}
