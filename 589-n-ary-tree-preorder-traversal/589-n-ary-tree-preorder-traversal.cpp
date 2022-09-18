/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre(Node* root, vector<int> &ans)
    {
        // preorder:rootLR
        if(root==NULL) return;
        ans.push_back(root->val);
        for(auto it: root->children)
        {
            pre(it, ans);
        }
    }
    vector<int> preorder(Node* root) {
        // in a normal tree we have either left and right child or there's just one child
        // here for every node we can have n childres
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};