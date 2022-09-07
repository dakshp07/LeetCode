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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) // we see the last node
        {
            if(root->val==targetSum)
            {
                return true;
            }
            return false;
        }
        bool lsum=hasPathSum(root->left, targetSum-root->val);
        bool rsum=hasPathSum(root->right, targetSum-root->val);
        return lsum || rsum;
    }
};