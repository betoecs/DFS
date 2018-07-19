#include "Node.hpp"

Node::Node(const std::string &name) : name(name), visited(false)
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

void Node::addNode(Node *node)
{
    nodes.push_back(node);
}
