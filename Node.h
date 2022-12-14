#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;
class Node {

private:
	Object* value ;
	Node* NextNode;


public:  // Constructors

	Node(Object* v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(Object* v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}
	friend class List;
	friend class Object;
};
typedef Node* PointerNode; //Alias

