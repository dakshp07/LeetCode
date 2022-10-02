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
    bool ans;
    int height(TreeNode* root)
    {
        // if we reach the last node then we return 0
        if(root==NULL) return 0;
        // if the ans==false we again return 0
        if(ans==false) return 0;
        // we recursively call for height
        int left=height(root->left);
        // we recursively call for height
        int right=height(root->right);
        // now we check the diff of height
        if(abs(left-right)>1) ans=false;
        // now we go ahead and return the height of the tree
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        // we use the find height function of bt
        ans=true;
        int temp=height(root);
        return ans;
    }
};