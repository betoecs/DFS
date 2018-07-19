#include "Graph.hpp"
#include <fstream>
#include <iostream>
#include <regex>

Graph::~Graph()
{
	for (auto node : nodes)
		delete node;
}

bool Graph::loadFromFile(const std::string &filename)
{
	std::ifstream file(filename);

	if (! file.is_open())
	{
		std::cout << "Graph: Unable to open file " << filename << std::endl;
		return false;
	}

	std::string command;
	while (std::getline(file, command))
		doCommand(command);

	file.close();
	return true;
}

Node * Graph::createNode(const std::string nodeName)
{
	Node *node = getNode(nodeName);
	if (! node)
	{
		nodes.push_back(new Node(nodeName));
		node = nodes.back();
	}

	return node;
}

Node * Graph::getNode(const std::string &nodeName)
{
	for (auto node : nodes)
		if (node->getName() == nodeName)
			return node;

	return nullptr;
}

const Node * Graph::getNode(const std::string &nodeName) const
{
	for (auto node : nodes)
		if (node->getName() == nodeName)
			return node;

	return nullptr;
}

const std::vector <Node *> & Graph::getNodes() const
{
	return nodes;
}

std::vector <Node *> & Graph::getNodes()
{
	return nodes;
}

void Graph::createRelationship(Node *nodeA, Node *nodeB, bool reciprocal)
{
	nodeA->addNode(nodeB);

	if (reciprocal)
		nodeB->addNode(nodeA);
}

void Graph::doCommand(const std::string &command)
{
	std::regex commandRegEx("(.+)( |\t)*,( |\t)*(-|>|<),( |\t)*(.+)( |\t)*");
	std::smatch match;

	if (! std::regex_match(command, match, commandRegEx))
		return;

	std::string relatioship(match [4]);
	Node *nodeA = createNode(match [1]);
	Node *nodeB = createNode(match [6]);

	if (relatioship == "<")
		createRelationship(nodeB, nodeA, false);
	else if (relatioship == ">")
		createRelationship(nodeA, nodeB, false);
	else
		createRelationship(nodeA, nodeB, true);
}

void Graph::dfs(Node *initialNode)
{
	auto currentNode = initialNode;
	std::vector <Node *> unvisitedNeighbours;
	std::stack <Node *> prevNodes;

	int counter = 1;
	currentNode->setEntry(counter++);
	currentNode->visit();
	prevNodes.push(currentNode);

	while (currentNode)
	{
		currentNode->getUnvisitedNeighbours(unvisitedNeighbours);

		if (unvisitedNeighbours.size())
		{
			currentNode = unvisitedNeighbours [0];
			unvisitedNeighbours.clear();

			currentNode->visit();
			currentNode->setEntry(counter++);
			prevNodes.push(currentNode);
		}
		else
		{
			currentNode->setExit(counter++);
			prevNodes.pop();

			if (prevNodes.size())
				currentNode = prevNodes.top();
			else
			{
				bool foundNode = false;
				for (auto node : nodes)
				{
					if (! node->isVisited())
					{
						currentNode = node;
						currentNode->visit();
						currentNode->setEntry(counter++);
						prevNodes.push(currentNode);
						foundNode = true;
						break;
					}
				}

				if (! foundNode)
					currentNode = nullptr;
			}
		}
	}
}

void Graph::bfs(Node *initialNode)
{
	Node *currentNode = initialNode;
	std::vector <Node *> nodesAtDistance;

	nodesAtDistance.push_back(currentNode);
	currentNode->setDistance(0);

	while (nodesAtDistance.size())
	{
		currentNode = nodesAtDistance.front();
		auto &neighbours = currentNode->getNeighbours();
		int distance = currentNode->getDistance();

		for (auto neighbour : neighbours)
		{
			neighbour->setDistance(distance + 1);
			nodesAtDistance.push_back(neighbour);
		}

		nodesAtDistance.erase(nodesAtDistance.begin());
	}
}
