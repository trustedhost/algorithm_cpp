#include <iostream>
#include <queue>

/* 요세푸스 문제.  */

int solution(int n, int k) {
    std::queue<int> q;
    for(int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main() {
    int answer = solution(5, 2);
    std::cout << answer << '\n';
    return 0;
}
