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
        // will use a queue to store the root and then push it on to the queue
        // further we will check for their left and right
        vector<vector<int>> ans; // for final ans
        // if root is null we return ans
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        // push the root
        q.push(root);
        // we will check till our queue becomes empty
        while(!q.empty())
        {
            vector<int> level; // temp array to store level
            int sz=q.size(); // queue size
            // iterate over the queue as we will pop first ele and add more in it
            for(int i=0; i<sz; i++)
            {
                // we will first check the top of queue
                TreeNode *node=q.front();
                // lets remove this from pop
                q.pop();
                // lets see if they have child on left and right
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                // we will push our node values to a vector
                level.push_back(node->val);
            }
            // push level to ans;
            ans.push_back(level);
        }
        return ans;
    }
};