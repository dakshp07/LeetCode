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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // if we reach end without any returns in b/w then we return NULL because then p,q dont exist in BST
        if(root==NULL) return NULL;
        // basically if we see a node whose val>p and <q then thats our lca
        // beacuse after that p,q will descend into their own trees
        if(root->val<p->val && root->val<q->val)
        {
            // if val<p and <q means we need to go to right subtree
            return lca(root->right, p, q);
        };
        if(root->val>p->val && root->val>q->val)
        {
            // if val>p and >q means we need to go to left subtree
            return lca(root->left, p, q);
        };
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // basically the node where node p, q diverge into their own path is the lca
        return lca(root, p, q);
    }
};