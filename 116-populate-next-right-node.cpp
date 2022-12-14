/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // so we can do it recursively or iteratively
        // i usually prefer recursion
        // base case:
        // 1. if we go past last node
        if(root==NULL) return nullptr;
        if(root->left!=NULL)
        {
            root->left->next = root->right; // using next to point left nodes to right
            root->right->next = root->next? root->next->left : NULL; // doing same for right
        }
        // recursive call for other nodes
        Node* left = connect(root->left);
        Node* right = connect(root->right);
        return root;
    }
};
