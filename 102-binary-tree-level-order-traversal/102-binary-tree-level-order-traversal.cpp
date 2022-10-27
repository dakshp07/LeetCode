/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // we use a queue to do this order traversal
        // we push all the level nodes and then push all their left,right children to vector
        // this is to a bfs, where we see a node and add its children to queue
        // and at the same time we push root node to vector
        if(root==NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root); // we start from root
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> lvl;
            for(int i=0; i<sz; i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                lvl.push_back(node->val);
            }
            res.push_back(lvl);
        }
        return res;
    }
};