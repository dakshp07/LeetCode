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
    bool path(TreeNode* root, int targetSum)
    {
        // base case
        // 1. if the root is null we return false since there's no node
        if(root==NULL) return false;
        // 2. if we reach end of tree and our targetSum-root->val!=0 we return false
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum-root->val!=0) return false;
            return true; // if targetSum becomes 0 we return true
        }
        // now we recursively call for left,right
        // and if through any of the one path we get targetSum==0 we return true
        return path(root->right, targetSum-root->val) || path(root->left, targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // so we recursively call for left,right subtrees
        if(root==NULL) return false;
        return path(root, targetSum);
    }
};