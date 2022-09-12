#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class ProductAisle : public Object {

private:

	int productId;

	int makeId;

public:

	ProductAisle() {

	}

	ProductAisle(int id, string name, int productId) : Object(id, name) {
		this->productId = productId;
	}

	int getProductId() {
		return this->productId;
	};

	void setProductId(int productId) {
		this->productId = productId;
	};

	int getMakeProductId() {
		return this->makeId;
	};

	void setMakeProductId(int makeId) {
		this->makeId = makeId;
	};

	friend class List;
};

