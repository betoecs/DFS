#ifndef MENU_HPP
#define MENU_HPP

#include "Graph.hpp"
#include <iostream>

/////////////////////////////////////////////
// Prints the nodes of the graph
/////////////////////////////////////////////
void printNodes(const Graph &graph);

/////////////////////////////////////////////
// Prints a menu to choose a initial node
// by its name and prints the paths of that
// node in the graph
/////////////////////////////////////////////
void getPaths(const Graph &graph);

#endif // MENU_HPP
