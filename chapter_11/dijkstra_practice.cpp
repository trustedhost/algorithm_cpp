#include <tuple>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
vector<pair<int, int>> graph[MAX_NODES]; // {destination, weight}

vector<int> solution(int start, int nodeNum, vector<tuple<int, int, int>> edges) {
    //initialize graph.
    for(int i = 0; i < nodeNum; ++i) {
        graph[i].clear();
    }
    //update edges
    for (const auto&[from, to, weight] : edges) {
        graph[from].emplace_back(to, weight);
    }
    //distances
    vector<int> distances(nodeNum, INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int minDistance = pq.top().first;
        int closestNode = pq.top().second;
        pq.pop();

        if (distances[closestNode] < minDistance) continue;
        //check all the neighbor nodes of the min Node. 
        for (const auto& [destination, weight] : graph[closestNode] ) {
            int newDistance = minDistance + weight;
            if (newDistance < distances[destination]) {
                distances[destination] = newDistance;
                pq.emplace(newDistance, destination);
            }
        }
    }
    return distances;
}

int main() {
    return 0;
}
