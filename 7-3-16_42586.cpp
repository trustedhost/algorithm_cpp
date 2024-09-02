/* 42586 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days_needed(progresses.size());
    for(int i = 0; i < progresses.size(); ++i){
        int todo = (100 - progresses[i]) ;
        if (todo % speeds[i]) {
            days_needed[i] = todo / speeds[i] + 1;
        } else {
            days_needed[i] = todo / speeds[i];
        }
    }
    std::queue<int> q;
    for (auto elem : days_needed) {
        q.push(elem);
    }
    while (!q.empty()) {
        int chunk = 0;
        int done = q.front();
        q.pop();
        chunk++;
        while ( done >= q.front() && !q.empty()) {
            q.pop();
            chunk++;
        }
        answer.push_back(chunk);
    }
        
    return answer;
}
