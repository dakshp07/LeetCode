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
    void invert(TreeNode* root)
    {
        // if we reach end we return the function call
        if(root==NULL) return;
        // now we swap our nodes value
        swap(root->right, root->left);
        // and go on for other nodes
        invert(root->right);
        invert(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        // we just need to swap the two values in left,right
        invert(root);
        return root;
    }
};