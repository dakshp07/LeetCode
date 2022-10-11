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
    bool checkSymmetry(TreeNode* left, TreeNode* right)
    {
        // if both are null then we return true
        if(left==NULL && right==NULL) return true;
        // if any of them is null we return false
        // if the right, left node value are diff we return false
        if(left==NULL || right==NULL || left->val!=right->val) return false;
        // now we move to the other nodes
        // simultaneously
        return checkSymmetry(left->right, right->left) && checkSymmetry(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        // so we start a recursive call
        // and check if the left half is equal to right half or not
        return checkSymmetry(root->left, root->right);
    }
};