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
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        // if our root and subroot both are null we return true as they are same
        if(root==NULL && subRoot==NULL) return true;
        // now if root and subroot are not null and have same val we call recursively for their right and left
        if(root!=NULL && subRoot!=NULL && root->val==subRoot->val)
        {
            // we call for left and right
            return isSame(root->right, subRoot->right) && isSame(root->left, subRoot->left);
        }
        // we return false in all other cases
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if the root is null then we dont have a subtree so return false
        if(root==NULL) return false;
        // now we see if both roots are have same value
        if(root->val==subRoot->val)
        {
            // we call for the same func
            if(isSame(root, subRoot)) return true;
        }
        // now we recursively check for right and left half
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};