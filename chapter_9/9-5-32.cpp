#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Node {
    Node* left;
    Node* right;
    int x;
    int y;
    int index;
};

class BinaryTree {
private:
    Node* root = nullptr;
    static bool compareNodes(Node* a, Node* b) {
        if (a->y != b->y) return a->y > b->y; 
        else return a->x < b->x;
    }
    Node* addNode(Node* current, Node* newNode) {
        if (current == nullptr) {
            return newNode;
        } else {
	        if (newNode->x < current->x) {
	            current->left = addNode(current->left, newNode);
	        } else {
	            current->right = addNode(current->right, newNode);
	        }
            return current;
        }
    }
    void preOrder(Node* node, vector<int>& traversal) {
        if (node == nullptr) return;
        traversal.push_back(node->index);
        preOrder(node->left, traversal);
        preOrder(node->right, traversal);
    }
    
public:
    void makeTree(vector<vector<int>> nodeinfo) {
        vector<Node*> nodes;
        for (int i = 0; i < nodeinfo.size(); ++i) {
            int index = i + 1;
            nodes.push_back(new Node{nullptr, nullptr, nodeinfo[i][0], nodeinfo[i][1], index});
        }
        sort(nodes.begin(), nodes.end(), compareNodes);
    	for (const auto& elem : nodes) {
            root = addNode(root, elem);
        }    
    }
    vector<int> getPreOrderTraversal() {
        vector<int> traversal;
        preOrder(root, traversal);
        
        return traversal;
    }
    
    
    
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    BinaryTree tree;
    tree.makeTree(nodeinfo);
    answer.push_back(tree.getPreOrderTraversal());
    
    
    return answer;
}