#include <vector>
#include <unordered_map>

using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {}
    int find(int node) {
        if (parent[node] == -1) {
            return node;
        } 
        return parent[node] = find(parent[node]);
    }
    void merge(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root1] = root2;
                rank[root2]++;
            }
        }
    }
};

int solution(int n, vector<vector<int>> computers) {
    DisjointSet disjointset(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j]) {
                disjointset.merge(i, j);
            }
        }
    }
    
    unordered_map<int, bool> networkFound;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int root = disjointset.find(i);
        if (!networkFound[root]) {
            answer++;
            networkFound[root] = true;
        }
    }
    return answer;
}