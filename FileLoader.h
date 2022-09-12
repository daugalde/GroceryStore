#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

class FileLoader {

private:


public:
	FileLoader() { }

	~FileLoader();

	void LoadFiles();

	List ReadAndLoadAilesFile();

	List ReadAndLoadProductAileFile();

	List ReadAndLoadProductsFile();

	List ReadAndLoadInvetoryFile();

	List ReadAndLoadClientFile();
};

