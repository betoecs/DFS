#include "Graph.hpp"
#include "Menu.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Graph file not specified\n";
		return 0;
	}

	Graph graph;
	if (! graph.loadFromFile(argv [1]))
		return 0;

	char option;
	while (option != '4')
	{
		// Menu
		do
		{
			std::cout << "1. Print nodes\n" << "2. DFS\n" << "3. BFS\n" << "4. Exit\n" << "Enter an option:  ";
			std::cin >> option;
		} while (option < '1' || option > '4');

		switch (option)
		{
			case '1': printNodes(graph); break;
			//case '2': getPaths(graph); break;
			case '2': printDFS(graph); break;
		}
	}

	return 0;
}
