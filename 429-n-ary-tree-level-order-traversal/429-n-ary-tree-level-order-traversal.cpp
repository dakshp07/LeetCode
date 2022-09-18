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
    vector<vector<int>> levelOrder(Node* root) {
        // we do similar to what we did in normal levelorder of bt
        if(root==NULL) return {};
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> lvl;
            for(int i=0; i<sz; i++)
            {
                Node* node=q.front();
                q.pop();
                // instead of left, right we run a for loop to cover all children of that node
                for(auto it: node->children)
                {
                    if(it!=NULL) q.push(it);
                }
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};