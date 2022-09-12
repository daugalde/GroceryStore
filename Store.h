#pragma once
#include <iostream>
using namespace std;

class Store {

private:

	List aisles;
	List productAisles;
	List products;
	List invetory;
	List clients;


public:

	Store() {}

	Store(List aisles) {
		this->aisles = aisles;
	}

	List getAisles() {
		return aisles;
	};

	void setAiles(List aisles) {
		this->aisles = aisles;
	};

	List getProductAisles() {
		return productAisles;
	};

	void setProductAisles(List productAisles) {
		this->productAisles = productAisles;
	};

	List getProducts() {
		return products;
	};

	void setProducts(List products) {
		this->products = products;
	};


	List getInventory() {
		return invetory;
	};

	void setInventory(List invetory) {
		this->invetory = invetory;
	};

	List getClients() {
		return clients;
	};

	void setClients(List clients) {
		this->clients = clients;
	};

	friend class List;

};
