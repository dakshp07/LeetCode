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
    void getAns(TreeNode* root, int &ans, bool left)
    {
        if(root==NULL) return;
        if(left && root->left==NULL && root->right==NULL) 
        {
            ans+=root->val;
        }
        getAns(root->left, ans, true);
        getAns(root->right, ans, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // use recursion reach the end and add their values
        // we also take help of boolean which will be true if the current node is left and false if current node is right
        int res=0;
        getAns(root, res, false); // start as false since we are at root
        return res;
    }
};