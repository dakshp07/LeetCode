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
    void inorder(TreeNode* root, int &k)
    {
        // base case is if we reach the end we return
        if(root==NULL) return;
        // we call for left
        inorder(root->left, k);
        // now we decrement k
        k-=1;
        // now when we at root, we check if k==0
        if(k==0)
        {
            ans=root->val;
            return;
        }
        // we call for right
        inorder(root->right, k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        // so we know that inorder of bst is always sorted
        // we can do one thing, we store the inorder in an array and return (k-1)th ele
        // tc: O(no of nodes) and sc: O(no of nodes) to store (excluding recursion stack space)
        // we can remove the sc and make it constant as we will return ele recursively
        // tc: O(no of nodes) and sc: O(1) (excluding recursion stack space)
        // inorder: LrootR
        inorder(root, k);
        return ans;
    }
};