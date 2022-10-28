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
    int ans=0;
    void ways(TreeNode* root, int targetSum, long long &curr)
    {
        // curr stores the current sum
        if(root==NULL) return;
        // we add nodes val to curr
        curr+=root->val;
        // and check if its equal to targetSum
        // if its we increment ans
        if(curr==targetSum) ans++;
        // call for left,right subtree
        ways(root->left, targetSum, curr);
        ways(root->right, targetSum, curr);
        // we need to backtrack too
        curr-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        // so in normal path sum we go through the left, right subtree
        // and check if we get the targetSum to zero and return true/false accordingly
        // but now we keep a count of the path
        if(root==NULL) return 0;
        long long curr=0;
        // call our function
        ways(root, targetSum, curr);
        // now we call pathSum function for our left, right subtree nodes
        pathSum(root->left,targetSum); //taking left child as root and calling pathSum function
        pathSum(root->right,targetSum); // taking left child as root and calling pathSum function
        return ans;
    }
};