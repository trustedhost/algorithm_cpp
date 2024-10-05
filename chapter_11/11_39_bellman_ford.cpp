#include <limits>
#include <tuple>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();
vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
    vector<vector<pair<int, int>> graph(num_vertices); // adjList

    for (auto& edge : edges) {
        int from, to, weight;
        tie(from, to, edge) = edge;
        graph[from].emplace_back(to,weight);
    }

    vector<int> distance(num_vertices, INF);
    distance[source] = 0;

    for (int i = 0; i < num_vertices - 1; ++i) {
        for (int u = 0; u < num_vertices; ++u) {
            for (const auto&[v, weight] : graph[u]) {
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < num_vertices; ++u) {
        for (const auto&[v, weight] : graph[u]) {
            if (distance[u] + weight < distance[v]) {
                return vector<int> (1, -1);
            }
        }
    }
    return distance;

}