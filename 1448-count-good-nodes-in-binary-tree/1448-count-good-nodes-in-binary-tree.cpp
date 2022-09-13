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
    int cnt_goodNodes(TreeNode *root, int prev)
    {
        if(root==NULL) return 0;
        if(root->val>=prev) // means i will cnt this node in my ans
        {
            // i will add this node and continue looking in its left, right by updating prev
            return 1+cnt_goodNodes(root->left, root->val)+cnt_goodNodes(root->right, root->val);
        }
        // if current root val is < prev then we dont add +1 and continue to look in right, left direction with prev being our max right now
        return cnt_goodNodes(root->left, prev)+cnt_goodNodes(root->right, prev);
    }
    int goodNodes(TreeNode* root) {
        int prev=INT_MIN;
        int ans=cnt_goodNodes(root, prev);
        return ans;
    }
};