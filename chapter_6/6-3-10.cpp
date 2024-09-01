#include <iostream>
#include <vector>
#include <sstream>
#include <string>
/* decimal to binary */

std::string solution(int number) {
    if (number == 0) return "0";
    std::stringstream ss;
    while ( number != 0 ) {
        ss << number % 2;
        number = number / 2;
    }
    std::string answer = ss.str();
    std::reverse(answer.begin(), answer.end());
    return answer;
}

std::string solution_2(int number) {
    if (number == 0 ) return "0";

    std::vector<int> stack;
    while (number != 0 ) {
        stack.push_back(number % 2);
        number /= 2;
    }

    std::string binary("");

    while (!stack.empty()) {
        binary += std::to_string(stack[stack.size() - 1]);
        stack.pop_back();
    }
    return binary;
    
}

int main() {
    std::cout << solution(10) << '\n';
    std::cout << std::to_string(130) + " world" << '\n';
}
