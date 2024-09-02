/* 42584 */
#include <string>
#include <vector>

/* O(N^2) */
std::vector<int> solution(std::vector<int> prices) {
	std::vector<int> answer(prices.size(), 0);
    for (int i = 0; i < prices.size() - 1; ++i) {
        int current_price = prices[i];
        for (int j = i + 1; j < prices.size(); ++j) {
            if (prices[j] < current_price) {
                answer[i] = j - i;
                break;
            }
        }
        if (answer[i] == 0) answer[i] = prices.size() - 1 - i;
    }
    return answer;
}

/* O(N) */
std::vector<int> solution2(std::vector<int> prices) {
    std::stack<int> stack;
    std::vector<int> answer(prices.size());
    for (int i = 0; i < prices.size(); ++i) {
        while (!stack.empty() && prices[stack.top()] > prices[i]) {
            answer[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    while (!stack.empty()) {
        answer[stack.top()] = prices.size() - 1 - stack.top();
        stack.pop();
    }
    return answer;
}
