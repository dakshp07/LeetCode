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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left_tree=height(root->left);
        int right_tree=height(root->right);
        return 1+max(left_tree, right_tree);
    }
    int maxDepth(TreeNode* root) {
        // we use the height function where height is 1+max(left-tree,right-tree)
        int ans=height(root);
        return ans;
    }
};