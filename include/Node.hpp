#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

/////////////////////////////////////////////
// A node of a graph. It has a name, a boolean
// value to determine if it has been visited and
// a list of nodes which are its neighbours.
/////////////////////////////////////////////
class Node
{
public:
	/////////////////////////////////////////////
	// Constructs a node initializing its name and
	// the visited attribute.
	/////////////////////////////////////////////
    Node(const std::string &name);

	/////////////////////////////////////////////
	// Gets the name of the node.
	/////////////////////////////////////////////
	const std::string & getName() const;

	/////////////////////////////////////////////
	// Sets visited to true.
	/////////////////////////////////////////////
    void visit();

	/////////////////////////////////////////////
	// Tells if the node has been visited or not.
	/////////////////////////////////////////////
    bool isVisited() const;

	int getEntry() const;

	void setEntry(int entry);

	int getExit() const;

	void setExit(int entry);

	int getDistance() const;

	void setDistance(int distance);

	std::vector <Node *> & getNeighbours();

	void getUnvisitedNeighbours(std::vector <Node *> &neighbours);

	/////////////////////////////////////////////
	// Sets visited to false and entry and exit to 0.
	/////////////////////////////////////////////
	void resetMetadata();

	/////////////////////////////////////////////
	// Adds a node as neighbour of this node.
	/////////////////////////////////////////////
	void addNode(Node *node);

	static int infiniteDistance;

private:
	/////////////////////////////////////////////
	// Indicates if the node has been visited or not.
	//
	// False by default and it's changed to true
	// by visit().
	/////////////////////////////////////////////
    bool visited;

	int entry;

	int exit;

	int distance;

	/////////////////////////////////////////////
	// The name of the node. Allows identify it
	// from others.
	//
	// It's set in the constructor and can be accessed
	// by getName()
	/////////////////////////////////////////////
    std::string name;

	/////////////////////////////////////////////
	// The neighbours nodes of the node.
	//
	// To add a neighbour node use addNode().
	/////////////////////////////////////////////
    std::vector <Node *> nodes;
};

#endif // NODE_HPP
