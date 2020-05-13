#include "interface.h"
#include "SortedList.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;

template<class T>
bool get_data(T& val, istream& in)
{
	in >> val;
	if (in.fail()) {
		return false;
	}
	return true;
}


void link(int N, string* list) {
	try {
		LinkedList l;
		for (size_t i = 0; i < N; i++) {
			l.Insert(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Find(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Erase(list[i]);
		}
	}
	catch (...) {}
}

void arr(int N, string* list) {
	try {
		ArrayList l;
		for (size_t i = 0; i < N; i++) {
			l.Insert(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Find(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Erase(list[i]);
		}
	}
	catch (...) {}
}

void tree(int N, string* list) {
	try {
		TreeList l;
		for (size_t i = 0; i < N; i++) {
			l.Insert(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Find(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Erase(list[i]);
		}
	}
	catch (...) {}
}

void avl(int N, string* list) {
	try {
		AVLList l;
		for (size_t i = 0; i < N; i++) {
			l.Insert(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Find(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Erase(list[i]);
		}
	}
	catch (...) {}
}

void tr23(int N, string* list) {
	try {
		List23 l;
		for (size_t i = 0; i < N; i++) {
			l.Insert(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Find(list[i]);
		}
		for (size_t i = 0; i < N; i++) {
			l.Erase(list[i]);
		}
	}
	catch (...) {}
}

void benchmark() {
	ofstream bench;
	bench.open("benchmark.txt");
	int N{ 10 }, d{ 10 };
	int times[5]{ 0 };
	void (*foos[])(int N, string * list) = { link, arr, tree, avl, tr23 };
	std::chrono::steady_clock::time_point start, end;

	bench << "Time in milliseconds" << endl;
	cout << "Time in milliseconds" << endl;

	string iters[3] = { "Random","Sorted","Sorted in inversion" };

	for (size_t i = 0; i < 3; i++) {
		N = d = 10;
		bench << iters[i] << endl;
		cout << iters[i] << endl;
		bench << setw(10) << "Count" << setw(10) << "Linked" << setw(10) << "Array" << setw(10) << "Tree" << setw(10) << "AVL" << setw(10) << "23-tree" << endl;
		cout << setw(10) << "Count" << setw(10) << "Linked" << setw(10) << "Array" << setw(10) << "Tree" << setw(10) << "AVL" << setw(10) << "23-tree" << endl;

		while (times[0] < 10000 || times[1] < 10000 || times[2] < 10000 || times[3] < 10000 || times[4] < 10000) {

			string* list = new string[N];
			for (size_t k = 0; k < N; k++) {
				list[k] = randstr();
			}

			switch (i)
			{
			case 0: break;
			case 1: sort_heap(&list[0], &list[N], [](const string& lhs, const string& rhs) {return lhs < rhs; }); break;
			case 2: sort_heap(&list[0], &list[N], [](const string& lhs, const string& rhs) {return lhs > rhs; }); break;
			default:
				break;
			}

			for (size_t i = 0; i < 5; i++) {
				start = std::chrono::steady_clock::now();
				foos[i](N, list);
				end = std::chrono::steady_clock::now();
				times[i] = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
			}

			bench << setw(10) << N;
			cout << setw(10) << N;
			for (size_t i = 0; i < 5; i++) {
				bench << setw(10) << times[i];
				cout << setw(10) << times[i];
			}
			bench << endl;
			cout << endl;

			if (times[0] < 1000 || times[1] < 1000 || times[2] < 1000 || times[3] < 1000 || times[4] < 1000) {
				N *= 2;
				d = N;
			}
			else {
				N += d;
			}
			delete[] list;
		}
	}
	bench.close();
}

string g_str;
void foo(string& val) {
	val += g_str;
}

void main_menu(istream& in) {
	cout << "Print 'help' for commands list" << endl << endl;
	string cmd, line;
	SortedList* list = nullptr;
	stringstream ss;
	while (true) {
		cmd = "";
		getline(in, line);
		ss.clear();
		ss.str(line);
		ss >> cmd;
		if (cmd == "help") {
			cout << "========================== COMMAND LIST ===========================" << endl;
			cout << "'linked' --- Save empty LinkedList" << endl;
			cout << "'array' --- Save empty ArrayList" << endl;
			cout << "'bintree' --- Save empty TreeList" << endl;
			cout << "'avltree' --- Save empty AVLList" << endl;
			cout << "'tree23' --- Save empty List23" << endl;
			cout << "'type' --- Print type of saved list" << endl;
			cout << "'del' --- Delete current saved list" << endl;
			cout << "'insert str' --- Insert element str" << endl;
			cout << "'erase str' --- Erase element str" << endl;
			cout << "'print' --- Print saved list" << endl;
			cout << "'foreach str' --- Add str to each element" << endl;
			cout << "'find str' --- Find element str in list" << endl;
			cout << "'find first last' --- Find elements in range [first, last]" << endl;
			cout << "'rand N' --- Insert N random elements in list" << endl;
			cout << "'demo' --- Launch demonstration mode" << endl;
			cout << "'bench' --- Launch benchmark mode" << endl;
			cout << "'exit' --- Close programm" << endl;
			cout << "====================================================================" << endl << endl;
		}
		else if (cmd == "find") {
			string first, last;
			if (!get_data(first, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (!ss.eof()) {
				if (!get_data(last, ss)) {
					cout << "Invalid input" << endl << endl;
					continue;
				}
				if (!list) {
					cout << "You haven't saved list" << endl << endl;
					continue;
				}
				else {
					try {
						vector<string> tmp = list->Find(first, last);
						for (const string& elem : tmp) {
							cout << elem << endl;
						}
						cout << endl;
					}
					catch (const exception& e) {
						cout << e.what() << endl << endl;
					}
					continue;
				}
			}
			if (!list) {
				cout << "You haven't saved list" << endl << endl;
				continue;
			}
			else {
				try {
					cout << "Element " << first << (list->Find(first) ? " was" : "wasn't") << " found" << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
				continue;
			}
		}
		else if (cmd == "del") {
			if (list) {
				delete list;
				list = nullptr;
				cout << "List successfuly deleted" << endl << endl;
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "insert") {
			string str;
			if (!get_data(str, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (list) {
				try {
					list->Insert(str);
					cout << "Successfuly added element " << str << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "print") {
			if (list) {
				list->Print();
				cout << endl;
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "type") {
			if (list) {
				cout << list->Type() << endl << endl;
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "rand") {
			int N;
			if (!get_data(N, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (list) {
				list->Random(N);
				cout << "Successfully added " << N << " random elements" << endl << endl;
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "erase") {
			string val;
			if (!get_data(val, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (list) {
				try {
					cout << "Element " << val << (list->Erase(val) ? " was deleted successfully" : " wasn't found") << endl << endl;
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "foreach") {
			if (!get_data(g_str, ss)) {
				cout << "Invalid input" << endl << endl;
				continue;
			}
			if (list) {
				try {
					list->ForEach(foo);
				}
				catch (const exception& e) {
					cout << e.what() << endl << endl;
				}
			}
			else {
				cout << "You haven't saved list" << endl << endl;
			}
		}
		else if (cmd == "linked") {
			if (list) {
				cout << "You already have saved list, delete it, if you want to create new one" << endl << endl;
			}
			else {
				list = new LinkedList;
				cout << "LinkedList successfuly saved" << endl << endl;
			}
		}
		else if (cmd == "array") {
			if (list) {
				cout << "You already have saved list, delete it, if you want to create new one" << endl << endl;
			}
			else {
				list = new ArrayList;
				cout << "ArrayList successfuly saved" << endl << endl;
			}
		}
		else if (cmd == "bintree") {
			if (list) {
				cout << "You already have saved list, delete it, if you want to create new one" << endl << endl;
			}
			else {
				list = new TreeList;
				cout << "TreeList successfuly saved" << endl << endl;
			}
		}
		else if (cmd == "avltree") {
			if (list) {
				cout << "You already have saved list, delete it, if you want to create new one" << endl << endl;
			}
			else {
				list = new AVLList;
				cout << "AVLList successfuly saved" << endl << endl;
			}
		}
		else if (cmd == "tree23") {
			if (list) {
				cout << "You already have saved list, delete it, if you want to create new one" << endl << endl;
			}
			else {
				list = new List23;
				cout << "List23 successfuly saved" << endl << endl;
			}
		}
		else if (cmd == "exit") {
			if (list)
				delete list;
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