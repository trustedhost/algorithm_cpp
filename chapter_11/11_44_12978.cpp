#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int INF = numeric_limits<int>::max();

int solution(int N, vector<vector<int> > road, int K) {
	
    vector<vector<pair<int, int>>> adjList(N + 1); // {v, weight}
    
    for (const auto& r : road) {
        int u = r[0];
        int v = r[1];
        int weight = r[2];
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }
    
    vector<int> distances(N + 1, INF);
    vector<bool> visited(N + 1, false); // index starts from 1
    
    //dijkstra algorithm
    
    distances[1] = 0;
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1}); // distance, target
    
    while (!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (visited[node]) continue;
        
        visited[node] = true;
        
        for (const auto&[next, weight] : adjList[node]) {
            int newDistance = dist + weight;
            if (newDistance < distances[next]) {
                distances[next] = newDistance;
                pq.push({newDistance, next});
            }
        }
    }
    int count = 0;
    
    for (int i = 1; i <= N; i++) {
        if (distances[i] <= K) {
            count ++;
        }
    }
    
    return count;
    
}    