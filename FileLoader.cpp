#include <fstream>
#include <iostream>
#include <string>
#include "FileLoader.h"
#include "Aisle.h"
#include "Store.h"
#include "ProductAisle.h"
#include "Product.h"
#include "Client.h"
#include "Inventory.h"

using namespace std;

FileLoader::~FileLoader()
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

void FileLoader::LoadFiles() {

	Store store;

	store.setAiles(ReadAndLoadAilesFile());

	store.setProductAisles(ReadAndLoadProductAileFile());

	store.setProducts(ReadAndLoadProductsFile());

	store.setInventory(ReadAndLoadInvetoryFile());

	store.setClients(ReadAndLoadClientFile());

	store.getAisles().display("aisle");

	store.getProductAisles().display("productAisle");

	store.getProducts().display("product");

	store.getInventory().display("inventory");

	store.getClients().display("client");

}

List FileLoader::ReadAndLoadAilesFile() {

	string str;

	ifstream file("Pasillos.txt");

	List list;

	while (!file.eof()) {

		getline(file, str);

		if(str != "") {
			Aisle* aisle = new Aisle();

			string delim = ";";

			size_t pos = 0;

			string token;

			while ((pos = str.find(delim)) != string::npos)
			{
				token = str.substr(0, pos);

				aisle->setId(stoi(token));

				str.erase(0, pos + delim.length());

			}
			aisle->setName(str);

			list.push(aisle);
		}
	}

	return list;
}

List FileLoader::ReadAndLoadProductAileFile() {

	string str;

	ifstream file("ProductosPasillos.txt");

	List list;

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			ProductAisle* productAisle = new ProductAisle();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 2 )
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					productAisle->setId(stoi(token));
				}
				else if (count == 1)
				{
					productAisle->setProductId(stoi(token));
				}
				else if (count == 2)
				{
					productAisle->setName(str);
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			list.push(productAisle);
		}
	}

	return list;
}

List FileLoader::ReadAndLoadProductsFile() {

	string str;

	ifstream file("MarcasProductos.txt");

	List list;

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {

			Product* product = new Product();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 5)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					product->setId(stoi(token));
				}
				else if (count == 1)
				{
					product->setProductId(stoi(token));
				}
				else if (count == 2)
				{
					product->setMakeId(stoi(token));
				}
				else if (count == 3)
				{
					product->setName(token);
				}
				else if (count == 4)
				{
					product->setShelfQuantity(stoi(token));
				}
				else if (count == 5)
				{
					product->setPrice(stof(str));
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			list.push(product);
		}
	}

	return list;
}

List FileLoader::ReadAndLoadInvetoryFile(){
	string str;

	ifstream file("Inventario.txt");

	List list;

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {

			Inventory* product = new Inventory();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 5)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					product->setId(stoi(token));
				}
				else if (count == 1)
				{
					product->setProductId(stoi(token));
				}
				else if (count == 2)
				{
					product->setMakeId(stoi(token));
				}
				else if (count == 3)
				{
					product->setName(token);
				}
				else if (count == 4)
				{
					product->setStockQuantity(stoi(token));
				}
				else if (count == 5)
				{
					product->setIsBasicBasket(stoi(str) == 1);
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			list.push(product);
		}
	}

	return list;
}

List FileLoader::ReadAndLoadClientFile(){
	string str;

	ifstream file("Clientes.txt");

	List list;

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Client* client = new Client();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 3)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					client->setId(stoi(token));
				}
				else if (count == 1)
				{
					client->setName(token);
				}
				else if (count == 3)
				{
					client->setPhone(token);
				}
				else if (count == 4)
				{
					client->setEmail(str);
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			list.push(client);
		}
	}

	return list;
}
