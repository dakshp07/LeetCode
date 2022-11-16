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
        // base case: if we reach the end of tree, we return null as we dont have nodes p,q
        if(root==NULL) return NULL;
        // now since its a bst we compare val of current node ie root with p,q
        // if p and q are <root, we go left
        if(root->val>p->val && root->val>q->val)
        {
            return lca(root->left, p, q);
        }
        // if p and q are >root, we go right
        if(root->val<p->val && root->val<q->val)
        {
            return lca(root->right, p, q);
        }
        // in other cases we know our lca will be root
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // lca is basically the node where we diverge to look for p, q
        // so we recursively call for both sides ie left, right
        return lca(root, p, q);
    }
};