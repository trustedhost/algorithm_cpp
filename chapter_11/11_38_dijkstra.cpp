#include <tuple>
#include <vector>
#include <limits>

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
vector<pair<int, int>> graph[MAX_NODES]; //{목적지, 가중치}

vector<int> solution(int start, int nodeNum, vector<tuple<int, int, int>> edges) {
    for (int i = 0; i < MAX_NODES; ++i) {
        graph[i].clear;
    }
    for (const auto& [from, to, weight] : edges) {
        graph[from].emplace_back(to, weight);
    }
    vector<int> distances(nodeNum, INF);
    distances[start] = 0;

    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start); // {weight, node}

    while (!pq.empty()){ 
        int closestNode = pq.front().second;
        int minDistance = pq.front().first;
        pq.pop();

        if (distances[closestNode] < minDistance) continue;

        for (const auto& [node, weight] : graph[closestNode]) {
            int newDistance = minDistance + weight;
            if (newDistance < distances[node]) {
                distanced[node] = newDistance;
                pq.emplace(newDistance, node);
            }
        }


    }


}