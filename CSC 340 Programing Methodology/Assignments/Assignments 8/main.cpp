#include "graph.h"
using namespace std;

int main()
{
	// Create a graph
	Graph<string> g;
	Node<string>* a = g.insert("a");
	Node<string>* b = g.insert("b");
	Node<string>* c = g.insert("c");
	Node<string>* d = g.insert("d");
	Node<string>* e = g.insert("e");
	g.connect(a, b);
	g.connect(c, d);
	g.connect(b, e);
	g.connect(c, e);
	cout << "Graph 1" << endl;
	g.print();
	cout << "-----" << endl;

	// Find the shortest path from "a" to "e".
	vector<Node<string>*> path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	// Create another graph, which is initially
	// just a copy of the first graph, and connect
	// "a" and "e" directly.
	Graph<string> g2(g);
	g2.connect("a", "e");
	cout << "Graph 1 again" << endl;
	g.print();
	cout << "-----" << endl;
	cout << "Graph 2" << endl;
	g2.print();
	cout << "-----" << endl;

	// Find the shortest path from "a" to "e"
	// in both graphs.
	path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	path = g2.shortestPath("a", "e");
	cout << "Graph 2: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	// Create a third graph.
	Graph<string> g3;
	g3.insert("z");         // this should get overwritten
	g3.insert("y");         // and this
	g3.connect("y", "z");   // also this

	// Set the third graph equal to the first
	// graph (making it a copy of the first
	// graph).
	g3 = g;
	g3.connect("a", "e");
	cout << "Graph 1 a third time" << endl;
	g.print();
	cout << "-----" << endl;
	cout << "Graph 3" << endl;
	g3.print();
	cout << "-----" << endl;

	// Find the shortest path from "a" to "e"
	// in the first and third graphs.
	path = g.shortestPath("a", "e");
	cout << "Graph 1: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	path = g3.shortestPath("a", "e");
	cout << "Graph 3: path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	system("pause");

	return 0;
}

