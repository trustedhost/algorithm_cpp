#include <iostream>
#include <vector>

using namespace std;

struct NodeInfo {
    int V; // 노드 번호. 
    int W; // 가중치 
};
vector<vector<NodeInfo>> adjList;

void addEdge(int u, int v, int w) {
    adjList[u].push_back(NodeInfo{v, w});
}

void printAdjList() {
    for (const auto& elem : adjList) {
        auto Iter = elem.begin();
        while (Iter != elem.end()) {
            cout << (*Iter).V << " - " << (*Iter).W << '\n';
            Iter++;
        }
        cout << '\n';
    }
}


int main() {
    int N = 5;
    adjList.resize(N);

    addEdge(1, 2, 3);
    addEdge(2, 1, 6);
    addEdge(2, 3, 5);
    addEdge(3, 2, 1);
    addEdge(3, 4, 13);
    addEdge(4, 4, 9);
    addEdge(4, 1, 42);

    printAdjList();

    return 0;
}
