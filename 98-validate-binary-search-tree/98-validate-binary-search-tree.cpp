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
    bool isValid(TreeNode* root, long left, long right)
    {
        // if we reach the last node that is null means we never returned anywhere so we return true
        if(root==NULL) return true;
        // if root->val is smaller than left value or greater than right we return false
        if(root->val<=left || root->val>=right) return false;
        // else we upate our left val and right val in our recursive call and keep moving
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        // we have to make sure that the rules of BST are followed
        // lets write a recursive func
        // we start with the max values that a left, right node can have ie long min, max respectively
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};