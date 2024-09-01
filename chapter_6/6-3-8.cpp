#include <iostream>
#include <vector>

using std::string;

bool solution(string s) {
    std::vector<char> stack;
    for (auto elem : s) {
        if (elem == '(') {
            stack.push_back(elem);
        } else if (elem == ')') {
            if (stack.empty()) {
                return false;
            } else {
                stack.pop_back();
            }
        }
    }
    return stack.empty();
}
int main() {
    string str("(())()(");
    std::cout << std::boolalpha << solution(str) << std::endl;
    return 0;
}

