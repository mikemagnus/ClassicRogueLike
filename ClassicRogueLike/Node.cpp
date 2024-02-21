#include "Node.hpp"

Node::Node(Node* p)
{
	parent = p;
	children = new std::vector<Node*>();
}

Node::~Node()
{
	free();
}

void Node::setParent(Node* p)
{
	if (p != NULL)
	{
		parent = p;
	}
}

Node* Node::getParent()
{
	return parent;
}

void Node::addChild(Node* child)
{
	if (child != NULL)
	{
		children->push_back(child);
		child->setParent(this);
	}
}

Node* Node::getChild(size_t index)
{
	return children->at(index);
}

std::vector<Node*>* Node::getChildren()
{
	return children;
}



void Node::free()
{
	//Release the parent
	parent = NULL;
	//Clear all children
	children->clear();
	//Erase the children vector
	SDL_free(children);
}
