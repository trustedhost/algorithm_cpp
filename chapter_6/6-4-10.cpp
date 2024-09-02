/*76502*/
#include <stack>
#include <string>
#include <iostream>

bool is_ok(std::string s) {
    std::stack<char> stack;
    for (auto elem : s) {
        if (elem == '(' || elem == '{' ||elem == '[') {
            stack.push(elem);
        } else if ( elem == ')') {
            if ( stack.empty() || stack.top() != '(') return false;
            else stack.pop();
        } else if ( elem == '}') {
            if ( stack.empty() || stack.top() != '{') return false;
            else stack.pop();
        } else if ( elem == ']') {
            if ( stack.empty() || stack.top() != '[') return false;
            else stack.pop();
        }
    }
    return stack.empty();
}

int solution(std::string s) {
    int rotations = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (is_ok(s)) rotations += 1;
        s = s.substr(1) + s[0];
    }
    return rotations;
}

