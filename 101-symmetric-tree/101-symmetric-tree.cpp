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
    bool helper(TreeNode* left, TreeNode *right)
    {
        // now we see if they are null or not
        if(left==NULL || right==NULL) return left==right;
        // next is to check the values of right and left, they should same if they are symmetric
        if(left->val!=right->val) return false;
        // we move to other nodes now
        // move to the right and left simultaneously
        return (helper(left->left, right->right) && helper(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        // the mirror property is that the right node on right side is the left node on the left side
        // right side: node->right
        // left side: node->left
        // so if we do inorder on right and left side independently
        // right side order: rootLR
        // left side order: rootRL
        // if(root==NULL) return false;
        return root==NULL || helper(root->left, root->right);
    }
};