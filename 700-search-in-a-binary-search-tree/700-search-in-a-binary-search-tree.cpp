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
    TreeNode* search(TreeNode* root, int val)
    {
        // if we reach the end of a tree
        // we return null since val isnt in the tree
        if(root==NULL) return NULL;
        // if we reach our val node we return root
        if(root->val==val) return root;
        // now we check for current node val
        // if its >val then we go on left subtree
        if(root->val>val) return search(root->left, val);
        // else if its <val we go on right
        return search(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        // we will call recursively
        // since its a bst at every node we check it value and go left/right accordingly
        return search(root, val);
    }
};