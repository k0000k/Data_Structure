#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> //µð¹ö±ë¿ë
#include <algorithm>

using namespace std;

class Polynomial {

public:
	void LoadPolynomial(std::string& filename);
	void PrintPolynomial();
	void add(Polynomial a, Polynomial b);
	vector<vector<int>> poly;
	bool first = true;
};