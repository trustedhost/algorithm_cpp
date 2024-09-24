#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    string name;
    Node* parent;
    int profit;
};

unordered_map<string, Node*> nodes;

void profitOrganize(Node* node, int profit) {
    int profitToGive = profit;
    Node* current = node;
    while (current->parent != nullptr && profitToGive != 0) {
        profitToGive = profitToGive / 10;
        current->profit -= profitToGive;
        current->parent->profit += profitToGive;
        current = current->parent;
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    Node* center = new Node{"John", nullptr, 0};
    nodes["John"] = center;
    for (int i = 0; i< enroll.size(); ++i) {
        string name = enroll[i];
        string refer = referral[i];
        if (refer == "-") {
            nodes[name] = new Node{name, center, 0};
        } else {
            nodes[name] = new Node{name, nodes[refer], 0};
        }
    }
    
    //initial profits
    for (int i = 0; i < seller.size(); ++i) {
        int profit = amount[i] * 100;
        nodes[seller[i]]->profit += profit;
        profitOrganize(nodes[seller[i]], profit);
    }
    
    
    vector<int> answer;
    for (auto& name : enroll) {
        answer.push_back(nodes[name]->profit);
    }
    return answer;
}