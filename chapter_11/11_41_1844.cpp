#include <vector>
#include <queue>
#include <tuple>

using namespace std;

static vector<int> dx = {0, 0, 1, -1};
static vector<int> dy = {1, -1, 0, 0};

int bfs(vector<vector<int>>& maps, pair<int, int> start, pair<int, int> exit) {
    int row = maps.size();
    int column = maps[0].size();
    
    vector<vector<bool>> visited(row, vector<bool>(column, false));
    queue<tuple<int, int, int>> q;
    
    q.push({start.first, start.second, 1});
   	visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        tuple<int, int, int> current = q.front();
        q.pop();
        
        int x, y, depth;
        tie(x, y, depth) = current;
        
        if (make_pair(x, y) == exit) {
            return depth;
        }
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < row && newY >= 0 && newY < column) {
                if (!visited[newX][newY] && maps[newX][newY] == 1) {
                    visited[newX][newY] = true;
                    q.push({newX, newY, depth + 1});
                } 
            }
        }
    }
    
    return -1;
    
}

int solution(vector<vector<int> > maps)
{
    int row = maps.size();
    int column = maps[0].size();
    pair<int, int> start = {0, 0};
    pair<int, int> exit = {row - 1, column - 1};
    
    int toExit = bfs(maps, start, exit);
   
    return toExit;
}