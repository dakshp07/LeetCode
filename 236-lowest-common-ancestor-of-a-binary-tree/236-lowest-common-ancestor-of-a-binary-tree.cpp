/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we start traverse from left to right
        // we keep going down and see if we reach any one of our target
        // in case we get one of our target, we revert it back to the parent
        // and then go to right to find other target, once we get target we return lca
        if(root==NULL || p==root || q==root) return root;
        // go to left
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        // go to rught
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        // if any of the two return null means we return other one
        if(left==NULL) return right;
        else if(right==NULL) return left;
        // if none of them is null means we got the answer
        else return root;
    }
};