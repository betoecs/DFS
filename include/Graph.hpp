#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"

/////////////////////////////////////////////
// A discrete math graph. It has a list of
// nodes.
//
// Can be created using a commands individually
// or inside of a file. Use doCommand() to
// indicate a single relationship betweeen nodes
// and loadFromFile() to read a whole file.
// These are possible commands:
//
// + **A,-,B**: Creates a node named A and another named
// B and establishes a bidirectional relationship.
// + **A,>,B**: Creates a node named A and another named
// B and adds B as neighbour of A.
// + **A,<,B**: Creates a node named A and another named
// B and adds A as neighbour of B.
/////////////////////////////////////////////
class Graph
{
public:
	/////////////////////////////////////////////
	// Frees the memory used by the nodes
	/////////////////////////////////////////////
	~Graph();

	/////////////////////////////////////////////
	// Reads a file of commands and execute them.
	//
	// Returns false if the file couldn't be openned.
	/////////////////////////////////////////////
	bool loadFromFile(const std::string &filename);

	/////////////////////////////////////////////
	// Creates a node with a given name and returns
	// a pointer to it.
	//
	// If the node already exists just return it.
	/////////////////////////////////////////////
	Node * createNode(const std::string nodeName);

	/////////////////////////////////////////////
	// Gets a pointer to a node of the graph.
	//
	// If the node doesn't exist returns nullptr.
	/////////////////////////////////////////////
	Node * getNode(const std::string &nodeName);

	/////////////////////////////////////////////
	// Returns a const pointer to a node of the graph
	//
	// If the node doesn't exist returns nullptr.
	/////////////////////////////////////////////
	const Node * getNode(const std::string &nodeName) const;

	/////////////////////////////////////////////
	// Gets a const reference to the nodes of the graph.
	/////////////////////////////////////////////
	const std::vector <Node *> & getNodes() const;

	/////////////////////////////////////////////
	// Gets a reference to the nodes of the graph.
	/////////////////////////////////////////////
	std::vector <Node *> & getNodes();

	/////////////////////////////////////////////
	// Creates a relationship between the node A
	// and the node B
	//
	// *reciprocal* indicates if the relationship
	// is bidirectional or not.
	/////////////////////////////////////////////
	void createRelationship(Node *nodeA, Node *nodeB, bool reciprocal);

	/////////////////////////////////////////////
	// Executes a command string with the following
	// structure: *NodeA,operation,NodeB* where
	// NodeA and NodeB are names of nodes
	// and operation can be '>', '<' or '-'.
	/////////////////////////////////////////////
	void doCommand(const std::string &command);

	void dfs(Node *initialNode);

private:
	/////////////////////////////////////////////
	// The nodes of the graph
	/////////////////////////////////////////////
	std::vector <Node *> nodes;
};

#endif // GRAPH_HPP
