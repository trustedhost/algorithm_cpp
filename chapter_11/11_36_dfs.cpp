#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
    visited.insert(node);
    result.push_back(node);

    for (char neighbor : adjList[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor);
        }
    }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
    for (const auto& elem : graph) {
        char u = elem.first;
        char v = elem.second;
        adjList[u].push_back(v);
    }

    dfs(start);

    return result;
}

template <typename Iter>
void print_vec(Iter start, Iter end) {
    Iter itr = start;
    while (itr != end) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << '\n';
}

int main() {
    vector<pair<char, char>> graph = {{'A', 'B'}, {'B', 'C'},{'C', 'D'},{'D', 'E'} };
    char start = 'A';

    vector<char> answer = solution(graph, start);
    print_vec(answer.begin(), answer.end());
    return 0;
}