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
    void inorder(TreeNode *root, int k)
    {
        // LrootR
        if(root==NULL) return;
        // int cnt=0; // we check through this
        inorder(root->left, k);
        cnt++;
        if(cnt==k) ans=root->val; // since the inorder is sorted order, we return when cnt == k
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // one way is to traverse and store the values heap
        // and return k-1 ele from heap
        // tc: O(n) for tree traversal and O(1) for insert and O(n) for accessing k-1 ele from heap
        // tc: O(n)
        // sc:O(n)
        // we can reduce the sc by keepina a count and doing inorder traversal
        // inorder is always sorted for bst and when count == k we return
        inorder(root, k);
        return ans;
    }
};