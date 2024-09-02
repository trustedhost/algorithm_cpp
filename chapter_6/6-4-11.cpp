/* 12973 */
#include <iostream>
#include <stack>

int solution(std::string s)
{
    std::stack<char> stack;
    for (auto elem : s) {
        if (stack.empty()) {
            stack.push(elem);
        } else {
            if (stack.top() == elem) {
                stack.pop();
            } else {
                stack.push(elem);
            }
        }
    }
    if (stack.empty()) return 1;
    else return 0;
}

int solution2(std::string s)
{
    std::stack<char> stack;
    for (auto elem : s) {
        if (stack.empty() || stack.top() != elem) stack.push(elem);
        else stack.pop();
    }
    return stack.empty() ? 1 : 0;
}

int main() {
    std::string str("baabaa");
    std::string str2("cdcd");

    std::cout << solution(str) << "\n";
    std::cout << solution(str2) << "\n";
}
