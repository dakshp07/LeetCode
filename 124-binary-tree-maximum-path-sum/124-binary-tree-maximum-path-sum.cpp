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
    int height(TreeNode *root, int &mx)
    {
        if(root==NULL) return 0;
        int lsum=max(0, height(root->left, mx));
        int rsum=max(0, height(root->right, mx));
        mx=max(mx, root->val+lsum+rsum);
        return max(lsum, rsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        height(root, mx);
        return mx;
    }
};