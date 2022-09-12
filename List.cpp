#include <iostream>
#include "Aisle.h"
#include "Node.h"
#include "List.h"
#include "ProductAisle.h"
#include "Product.h"
#include "Client.h"
#include "Inventory.h"

using namespace std;

List::~List()
{
	/*
	PointerNode aux;

	while (head) {
		aux = head;
		head = head->NextNode;
		delete aux;
	}

	head = NULL;
	*/
	
}

int List::Length() {
	int cont = 0;

	PointerNode aux = head;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::push(Object* obj)
{
	if (IsEmpty()) {
		head = new Node( obj);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node( obj);
	}
}

void List::display(string type)
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (type == "aisle")
			{
				cout << aux->value->getId() << aux->value->getName() << static_cast<Aisle*>(aux->value)->type << endl;
			}
			else if (type == "productAisle") {
				cout << aux->value->getId() << static_cast<ProductAisle*>(aux->value)->getProductId() << aux->value->getName() << endl;
			}
			else if (type == "product") {
				cout << aux->value->getId() << static_cast<Product*>(aux->value)->getProductId() << static_cast<Product*>(aux->value)->getMakeId()  << aux->value->getName() << static_cast<Product*>(aux->value)->getShelfQuantity() << static_cast<Product*>(aux->value)->getPrice() << endl;
			}
			else if (type == "inventory") {
				cout << aux->value->getId() << static_cast<Inventory*>(aux->value)->getProductId() << static_cast<Inventory*>(aux->value)->getMakeId() << aux->value->getName() << static_cast<Inventory*>(aux->value)->getStockQuantity()  << static_cast<Inventory*>(aux->value)->getIsBasicBasket() << endl;
			}
			else if (type == "client") {
				cout << aux->value->getId() << aux->value->getName()  << static_cast<Client*>(aux->value)->getPhone() << static_cast<Client*>(aux->value)->getEmail() << endl;
			}
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

