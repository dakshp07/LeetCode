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
        // if we reach end we return
        if(root==NULL) return ;
        // now we make two calls
        // one for right and other one for left
        // and swap the values
        swap(root->right, root->left);
        invert(root->right);
        invert(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        // so we keep just go to right and left subtree
        // swap the node, and recursively call for other nodes
        invert(root);
        return root;
    }
};