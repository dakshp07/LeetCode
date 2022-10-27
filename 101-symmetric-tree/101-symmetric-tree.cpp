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
    bool symmetric(TreeNode* left, TreeNode* right)
    {
        // base cases:
        // if we reach null in both sides of tree we return true
        // as we reach the bottom at same time
        if(left==NULL && right==NULL) return true;
        // the other base case would be when the values are diff, we return false
        // or when just one of them is null
        if(left==NULL || right==NULL) return false;
        if(left->val!=right->val) return false;
        // now we are done with bases cases
        
        // now next we need to go and check right left with left right
        // and vice versa because thats what symmetry is
        // if any of the is false we return false, so we use &&
        return symmetric(left->right, right->left) && symmetric(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        // so we write a recursive function to check the two sides of BT
        return symmetric(root->left, root->right);
    }
};