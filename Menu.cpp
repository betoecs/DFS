#include "Menu.hpp"

void printNodes(const Graph &graph)
{
	for (auto node : graph.getNodes())
		std::cout << node->getName() << std::endl;

	std::cout << std::endl;
}

void printDFS(Graph &graph)
{
	Node *initialNode = nullptr;
	while (! initialNode)
	{
		std::string initialNodeName;
		std::cout << "Name of initial node: ";
		std::cin >> initialNodeName;

		initialNode = graph.getNode(initialNodeName);
		if (! initialNode)
			std::cout << "That node doesn't exist\n";
	}

	graph.dfs(initialNode);
	for (auto node : graph.getNodes())
	{
		std::cout << node->getName() << "(" << node->getEntry() << ", " << node->getExit() << ")\n";
		node->resetMetadata();
	}
	std::cout << std::endl;
}

void printBFS(Graph &graph)
{
	Node *initialNode = nullptr;
	while (! initialNode)
	{
		std::string initialNodeName;
		std::cout << "Name of initial node: ";
		std::cin >> initialNodeName;

		initialNode = graph.getNode(initialNodeName);
		if (! initialNode)
			std::cout << "That node doesn't exist\n";
	}

	graph.bfs(initialNode);
	int distance = 0;
	bool nodesAtDistance = true;

	while (nodesAtDistance)
	{
		nodesAtDistance = false;
		std::cout << "Distance " << distance << ": ";

		for (auto node : graph.getNodes())
		{
			if (node->getDistance() == distance)
			{
				std::cout << node->getName() << " ";
				node->resetMetadata();
				nodesAtDistance = true;
			}
		}

		distance++;
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
