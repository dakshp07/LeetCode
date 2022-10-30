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
    bool valid(TreeNode* root, long long left, long long right)
    {
        // if we reach end means we return true
        if(root==NULL) return true; // as an empty bst is also valid
        // now check the conditions
        // if at any point we reach a node whose val is <=left or is >=right means we return false
        // as its not at correct position in bst
        if(root->val<=left || root->val>=right) return false;
        // now we go on left, right side of bst
        // for left side we check if all nodes are <right
        // for right side we check if all nodes are >left
        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        // we do a recursive call on nodes
        // we keep left,right vals and see if current node is >=left and <right 
        return valid(root, LONG_MIN, LONG_MAX); // since node->val can -231<=Node.val<=231-1
    }
};