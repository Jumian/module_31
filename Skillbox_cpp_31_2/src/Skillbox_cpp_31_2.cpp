#include <iostream>
#include "Graph_List.h"
#include "Graph_Matrix.h"
#include "Table_Print.h"

int main() {
	CLIPrinter printer;
	std::vector<int> res;
	GraphList graph1(10);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(3, 6);
	graph1.AddEdge(2, 6);
	graph1.AddEdge(3, 5);
	graph1.PrintCLI();
	graph1.GetNextVertices(2, res);
	printer.printVector(res,", ");
	graph1.GetPrevVertices(3, res);
	printer.printVector(res, ", ");
	GraphMatrix graph2(25);
	graph2.AddEdge(1, 2);
	graph2.AddEdge(2, 5);
	graph2.AddEdge(3, 5);
	graph2.AddEdge(3, 6);
	graph2.AddEdge(7, 9);
	graph2.PrintCLI();
	graph2.GetNextVertices(2, res);
	printer.printVector(res, ", ");
	graph2.GetPrevVertices(7, res);
	printer.printVector(res, ", ");

};