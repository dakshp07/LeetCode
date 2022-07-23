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
    bool isValid(TreeNode *root, long left, long right)
    {
        if(root==NULL) return true; // if we reach end without any false as return we give true
        // if node is out of the left, right bounds then return false
        if(root->val<=left || root->val>=right) return false;
        // else we continue traversing in left right by updating our boundaries
        // as i go on left my right boundary is updated with parent node val
        // and on going to left my left boundary is updated with parent node val
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        // we give a range to the nodes
        // the root starts with an range of [INT_MIN, INT_MAX]
        // corresponding nodes will have diff ranges
        // if they follow range, we return true and move to next thing else we return false
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};