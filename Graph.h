#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <fstream>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, list<pair<string, int>>> adjacencyList;
    unordered_map<string, bool> visited;
    std::vector<std::tuple<std::string, std::string, int>> savedConnections;
    std::vector<std::string> savedCities;


    void resetVisited();

public:
    void addCity(const string& city);
    void addEdge(const string& city1, const string& city2, int distance);   
   
    void deleteCity(const string& city);
    void deleteEdge(const string& city1, const string& city2);
    void displayGraph();
    void BFS(const string& startCity);
    void DFS(const string& startCity);
    void dijkstra(const string& startCity, const string& endCity);
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    vector<string> getAllCities();
    list<pair<string, int>> getEdge(const string& city);
    const unordered_map<string, list<pair<string, int>>>& getAdjacencyList() const {
        return adjacencyList;
    }
};

#endif