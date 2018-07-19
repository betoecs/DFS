#include "Node.hpp"

Node::Node(const std::string &name) : name(name), visited(false), entry(0), exit(0)
{
}

const std::string & Node::getName() const
{
	return name;
}

bool Node::isVisited() const
{
    return visited;
}

void Node::visit()
{
    visited = true;
}

int Node::getEntry() const
{
	return entry;
}

void Node::setEntry(int entry)
{
	this->entry = entry;
}

int Node::getExit() const
{
	return exit;
}

void Node::setExit(int exit)
{
	this->exit = exit;
}

void Node::getUnvisitedNeighbours(std::vector <Node *> &neighbours)
{
	for (auto neighbour : nodes)
		if (! neighbour->isVisited())
			neighbours.push_back(neighbour);
}

void Node::resetMetadata()
{
	visited = false;
	entry = 0;
	exit = 0;
}

void Node::addNode(Node *node)
{
    nodes.push_back(node);
}
