/* bfs */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adjList;
vector<int> result;

void bfs(int start) {
    unordered_set<int> visited;
    queue<int> q;
    visited.insert(start);
    q.push(start);
    result.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto& neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                result.push_back(neighbor);
            }
        }
    }
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
    for (const auto& elem : graph) {
        int u = elem.first;
        int v = elem.second;
        adjList[u].push_back(v);
    }
    bfs(start);
    return result;
}


template <typename Iter>
void print_vec(Iter start, Iter end) {
    Iter itr = start;
    while (itr != end) {
        std::cout << *itr << " " ;
        itr++;
    }
    std::cout << '\n';
}
int main() {
    vector<pair<int, int>> graph;
    graph.push_back({1, 2});
    graph.push_back({1, 3});
    graph.push_back({2, 4});
    graph.push_back({2, 5});
    graph.push_back({3, 6});
    graph.push_back({3, 7});
    graph.push_back({4, 8});
    graph.push_back({5, 8});
    graph.push_back({6, 9});
    graph.push_back({7, 9});
    int start = 1;

    vector<int> answer = solution(graph, start);
    print_vec(answer.begin(), answer.end());


}