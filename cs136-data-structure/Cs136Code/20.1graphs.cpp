#include <iostream>

#include "20graphType.h"
#include "20weightedGraph.h"

void Test20_1() {
	graphType myGraph(100);
	myGraph.createGraph();

	myGraph.depthFirstTraversal();
	cout << endl;
}

void Test20_2() {
	graphType myGraph(100);
	myGraph.createGraph();

	myGraph.breadthFirstTraversal();
	cout << endl;
}

void Test20_3() {
	int sourceVertex;

	weightedGraphType graph(50);

	graph.createWeightedGraph();

	graph.shortestPath();
	graph.printShortestDistance();

}