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
    TreeNode *prev=NULL;
    void flatten(TreeNode* root) {
        // tc: O(n) and sc: O(n)
        // we will push all the right children to left side and then make a linkedlist
        if(root==NULL) return;
        flatten(root->right); // call for right half first
        flatten(root->left); // left half comes next
        // remove connections
        root->right=prev; // the right becomes new connection with the other side nodes
        root->left=NULL; // the left becomes null
        prev=root; // update prev with the new root values and connection
    }
};