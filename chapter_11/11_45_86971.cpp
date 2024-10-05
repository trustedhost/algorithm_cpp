#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int node, int parent, vector<vector<int>>& graph) {
    int cnt = 1;
    for (auto& g : graph[node]) {
        if (g != parent) {
            cnt += dfs(g, node, graph);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    for (auto& wire : wires) {
        int a = wire[0];
        int b = wire[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);   
    }
    
    int min_diff = INT_MAX;
    
    for (auto & wire : wires) {
        int a = wire[0];
        int b = wire[1];
        
        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
        int cnt_a = dfs(a, b, graph);
        int cnt_b = n - cnt_a;
        min_diff = min(min_diff , abs(cnt_a - cnt_b));
        
        graph[a].push_back(b);
        graph[b].push_back(a);   
    }
    
    return min_diff;
}