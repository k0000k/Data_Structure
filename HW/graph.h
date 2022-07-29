#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Graph
{
public:
    int n;
    vector<vector<int>> graph;

    void LoadMatrix(std::string &filename);
    int GetSize();
    void PrintMatrix();
    void PrintShortestPathWeight(int s);
    void PrintShortestPath(int s);
};