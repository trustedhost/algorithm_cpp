#include <vector>
#include <stack>
#include <string>

struct Node {
    int index;
    Node* next;
    Node* prev;
};
std::string solution(int n, int k, std::vector<std::string> cmd) {
    std::vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node{i, nullptr, nullptr};
        if (i > 0) {
            nodes[i]->prev = nodes[i - 1];
            nodes[i - 1]->next = nodes[i];
        }
    }
    Node* current = nodes[k];
    std::stack<Node*> deleted;
    for (auto elem : cmd) {
        if (elem[0] == 'U') {
            int count = std::stoi(elem.substr(2));
            while (count-- > 0 && current->prev) current = current->prev;
        } else if (elem[0] == 'D') {
            int count = std::stoi(elem.substr(2));
            while (count-- > 0 && current->next) current = current->next;
        } else if (elem[0] == 'C') {
            deleted.push(current);
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            current = (current->next) ? current->next : current->prev;
        } else if (elem[0] == 'Z') {
            Node* restore = deleted.top();
            deleted.pop();
            if (restore->prev) restore->prev->next = restore;
            if (restore->next) restore->next->prev = restore;
        }
    }
    std::string answer(n, 'O');
    while (!deleted.empty()) {
        int del = deleted.top()->index;
        deleted.pop();
        answer[del] = 'X';
    }
    for (auto node : nodes) {
        delete node;
    }
    return answer;
}
