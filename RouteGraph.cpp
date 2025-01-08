#include "RouteGraph.h"

void RouteGraph::addRoute(const string& from, const string& to, int distance) {
    adjList[from].push_back({to, distance});
    adjList[to].push_back({from, distance});
}

vector<string> RouteGraph::findShortestPath(const string& start, const string& end) {
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    for (const auto& pair : adjList) {
        distances[pair.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentNode == end) {
            vector<string> path;
            for (string at = end; at != ""; at = previous[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : adjList[currentNode]) {
            int newDist = currentDistance + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                previous[neighbor.first] = currentNode;
                pq.push({newDist, neighbor.first});
            }
        }
    }
    return {};
}