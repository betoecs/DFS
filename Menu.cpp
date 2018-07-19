#include "Menu.hpp"

void printNodes(const Graph &graph)
{
	for (auto &node : graph.getNodes())
		std::cout << node.getName() << std::endl;

	std::cout << std::endl;
}

void getPaths(const Graph &graph)
{
	const Node *initialNode = nullptr;
	while (! initialNode)
	{
		std::string initialNodeName;
		std::cout << "Name of initial node: ";
		std::cin >> initialNodeName;

		initialNode = graph.getNode(initialNodeName);
		if (! initialNode)
			std::cout << "That node doesn't exist\n";
	}
}
