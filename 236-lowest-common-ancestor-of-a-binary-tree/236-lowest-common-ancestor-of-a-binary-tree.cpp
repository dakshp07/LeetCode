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
        // we will keep on looking for our lca, lca is basically the point where we diverge 
        // the point where we diverge into left and right of bt is lca
        
        // if root is null or if root is equal to p or q then root is our lca
        if(root==NULL || root==p || root==q) return root;
        
        // if we dont return here then we will recursively call for left side subtree and right subtree
        TreeNode *lf=lowestCommonAncestor(root->left, p, q);
        TreeNode *rf=lowestCommonAncestor(root->right, p, q);
        
        // if left is null then our ans is right and if right is null our ans is left
        if(lf==NULL) return rf;
        if(rf==NULL) return lf;
        
        // if none of them are null then root is the point where we diverge
        return root;
    }
};