/* 81303 */

#include <vector>
#include <stack>
#include <string>

std::string solution(int n, int k, std::vector<std::string> cmd) {
    std::vector<int> prev(n), next(n);
    std::stack<int> deleted;
    for(int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    int current = k;
    for (auto elem : cmd) {
        if (elem[0] == 'U') {
            int count = stoi(elem.substr(2));
            while (count != 0) {
                current = prev[current];
                count--;
            }
        } else if (elem[0] == 'D') {
            int count = stoi(elem.substr(2));
            while (count != 0) {
                current = next[current];
                count--;
            }
        } else if (elem[0] == 'C') {
            deleted.push(current);
            if (prev[current] != -1) next[prev[current]] = next[current];
            if (next[current] != -1) prev[next[current]] = prev[current];
            current = (next[current] != -1) ? next[current] : prev[current];
        } else if (elem[0] == 'Z') {
            int restore = deleted.top();
            deleted.pop();
            if (next[restore] != -1) prev[next[restore]] = restore;
            if (prev[restore] != -1) next[prev[restore]] = restore;
        }
    }

    std::string answer(n, 'O');
    while (!deleted.empty()) {
        int index = deleted.top();
        deleted.pop();
        answer[index] = 'X';
    }
    return answer;
}


