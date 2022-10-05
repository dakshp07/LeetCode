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
    int cnt=0;
    void inorder(TreeNode* root, int k)
    {
        // LrootR
        if(root==NULL) return;
        inorder(root->left, k);
        // we do cnt++ everytime
        cnt++;
        // we store answer when cnt==k
        if(cnt==k)
        {
            ans=root->val;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // we know that inorder of bst is always sorted
        // so we do an recursive inorder and at the same time keep track of cnt==k
        inorder(root, k);
        return ans;
    }
};