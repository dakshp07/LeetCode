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
        // base case: if root is null we return null
        if(root==NULL) return NULL;
        // now if root==p or q then we return p,q accordingly
        if(root->val==p->val || root->val==q->val) return root;
        // now we go on left, right side
        // if any of them returns null, that means the nodes are on other side
        TreeNode* right_node=lca(root->right, p, q);
        TreeNode* left_node=lca(root->left, p, q);
        if(right_node==NULL) return left_node;
        if(left_node==NULL) return right_node;
        // if in above cases we dont return ans, that means root is our lca
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // so lca is basically the node where we diverge
        // we can recursively call for both sides ie left, right
        return lca(root, p, q);
    }
};