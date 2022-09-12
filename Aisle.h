#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Aisle : public Object {
private:

	string type;

public:

	Aisle() {

	}

	Aisle(int id, string name, string type) : Object(id, name) {
		this->type = type;
	}

	friend class List;
};

