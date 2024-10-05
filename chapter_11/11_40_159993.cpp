#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

static vector<int> dx = {0, 0, 1, -1};
static vector<int> dy = {1, -1, 0, 0};

int bfs(vector<string>& maps, pair<int, int> start, pair<int, int> target) {
    int row = maps.size();
    int column = maps[0].length();
    
    vector<vector<bool>> visited(row, vector<bool>(column, false));
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        int x, y, depth;
        tie(x, y, depth) = q.front();
        q.pop();
        
        if (x == target.first && y == target.second) {
            return depth;
        }
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < row && newY >= 0 && newY < column) {
                if (!visited[newX][newY] && maps[newX][newY] != 'X')  {
                    visited[newX][newY] = true;
                    q.push({newX, newY, depth + 1});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int row = maps.size();
    int column = maps[0].length();
    
    pair<int, int> start, lever, exit;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (maps[i][j] == 'S') {
                start = {i, j};
            } else if (maps[i][j] == 'E') {
                exit = {i, j};
            } else if (maps[i][j] == 'L') {
                lever = {i, j};
            }
        }
    }
    //phase 1 : get lever
    int toLever = bfs(maps, start, lever); 
    if (toLever == -1) return -1;
    //phase 2 : get exit
    int toExit = bfs(maps, lever, exit); 
    if (toExit == -1) return -1;
    
    return toLever + toExit;
}