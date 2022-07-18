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
    void fun(TreeNode* node, int level, vector<int> &res)
    {
        if(node==NULL) return;
        // if our level == res.size() means we are at new level so we add
        if(level==res.size())
        {
            res.push_back(node->val);
        }
        // now we do recursive call to L, R nodes
        fun(node->right, level+1, res);
        fun(node->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        // we will do a reverse pre order
        // pre order: rootLR
        // reverse pre order: rootRL
        // we will call recursively
        // and keep an variable level to keep check
        vector<int> ans;
        if(root==NULL) return ans;
        // we do not need to push root here as we already start from 0
        fun(root, 0, ans);
        return ans;
    }
};