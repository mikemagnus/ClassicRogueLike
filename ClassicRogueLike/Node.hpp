#ifndef NODE_H
#define NODE_H

//Standard Libraries
#include <iostream>
#include <cmath>
#include <vector>

//SDL Libraries
#include <SDL.h>

class Node
{
public:
	//Must be called with a valid parent unless it is the game class which can have itself as parent.
	Node(Node* p);

	~Node();

	void setParent(Node* p);
	Node* getParent();

	void addChild(Node* child);
	Node* getChild(size_t index);
	std::vector<Node*>* getChildren();

	virtual void update() = 0;

	void free();

private:
	Node* parent;
	std::vector<Node*>* children;
};


#endif