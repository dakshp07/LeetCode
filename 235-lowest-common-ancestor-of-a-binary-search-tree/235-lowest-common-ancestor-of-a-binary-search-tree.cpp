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
        // we go around the left or right side acc to values of p,q
        // and the point where we diverge is the point of our LCA and we return that as our ans
        if(root==NULL) return NULL;
        int curr=root->val; // get the val at root node
        // if both p,q are bigger than root node we go to right
        if(curr<p->val && curr<q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // if both p,q are smaller than root node we go to left
        if(curr>p->val && curr>q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};