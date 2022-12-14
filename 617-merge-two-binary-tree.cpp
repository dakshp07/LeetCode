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
    TreeNode* merge(TreeNode* root1, TreeNode* root2)
    {
        // base case:
        // 1. if any of them is null we return other one
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        // now we create a new tree with its root node as sum of both roots
        TreeNode* new_tree=new TreeNode(root1->val+root2->val);
        // now we recursively fill new tree's left, right
        new_tree->left=merge(root1->left, root2->left);
        new_tree->right=merge(root1->right, root2->right);
        return new_tree;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // we just do whatever the explantion says
        // and merge both into a new tree recursively
        return merge(root1, root2);
    }
};
