#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    std::stack<int> stack;
    //std::cout <<  stack.top() << '\n'; // error 발생. 
    stack.push(10);
    std::cout <<  stack.top() << '\n';
    std::cout << "Front : " << q.front() << '\n';
    q.pop();
    std::cout << "Front : " << q.front() << '\n';
    q.pop();
    std::cout << "Front : " << q.front() << '\n';
    q.pop();
    std::cout << "Front : " << q.front() << '\n';

    std::cout << std::boolalpha << q.empty() << '\n';
    q.pop();
    std::cout << "Front : " << q.front() << '\n';

    std::cout << std::boolalpha << q.empty() << '\n';


}
