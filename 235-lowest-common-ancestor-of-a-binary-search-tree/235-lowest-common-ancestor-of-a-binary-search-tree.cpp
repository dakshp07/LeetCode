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
        // if we reach end then we return null as lca
        if(root==NULL) return NULL;
        // now we see the current node val and compare it with p,q
        if(root->val>p->val && root->val>q->val) 
        {
            // if current node val is greater than both p,q val
            // it means our lca will on left side
            return lca(root->left, p, q);
        }
        if(root->val<p->val && root->val<q->val) 
        {
            // if current node val is less than both p,q val
            // it means our lca will on right side
            return lca(root->right, p, q);
        }
        // in all other cases ie current node is >p and <q means root is our lca
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we go recursively
        // if at any node we diverge we return that node as our ans
        return lca(root, p, q);
    }
};