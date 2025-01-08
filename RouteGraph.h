#ifndef ROUTEGRAPH_H
#define ROUTEGRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

class RouteGraph {
public:
    unordered_map<string, vector<pair<string, int>>> adjList;

    void addRoute(const string& from, const string& to, int distance);
    vector<string> findShortestPath(const string& start, const string& end);
};

#endif // ROUTEGRAPH_H