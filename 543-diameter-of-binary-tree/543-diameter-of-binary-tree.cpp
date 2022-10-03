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
    int ans;
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        // now we store the ans in ans variable
        ans=max(ans, left+right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // we will use the height function and keep a track of the maximum height
        // and then return that
        ans=-1e9;
        int temp=height(root);
        return ans;
    }
};