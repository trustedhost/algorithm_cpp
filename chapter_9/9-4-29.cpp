#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int key) : data(key), left(nullptr), right(nullptr) {};
};

class BST {
private: 
    Node* root;
    Node* insertNode(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }
        if ( key < node->data) {
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }
        return node;
    }
    bool searchNode(Node* node, int key) {
        if (!node) {
            return false;
        }

        if (key == node->data) {
            return true;
        }
        return key < node->data ? searchNode(node->left, key) : searchNode(node->right, key);
    }

public:
    BST() : root(nullptr) {}
    void insert(int key) {
        root = insertNode(root, key);
    }
    bool search(int key) {
        return searchNode(root, key);
    }

};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
    BST bst;
    for (int key : lst) {
        bst.insert(key);
    }

    vector<bool> answer;

    for (int search_val : search_lst) {
        answer.push_back(bst.search(search_val));
    }
    return answer;
}
int main() {
    vector<bool> result = solution({5, 3, 8, 4, 2, 1, 7, 10}, {1, 2, 5, 6});
    for (const auto& elem : result) {
        std::cout << std::boolalpha << elem << " " ;
    }

    
    return 0;
}
