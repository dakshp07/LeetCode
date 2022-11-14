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
    void revPreorder(TreeNode* root, int level, vector<int> &ans)
    {
        // base case: if we reach end of tree we return
        if(root==NULL) return;
        // else we check level value and if its equal to ans.size()
        // that means we are at new level so we push
        if(level==ans.size()) ans.push_back(root->val);
        // now we go right, left one by one
        revPreorder(root->right, level+1, ans);
        revPreorder(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        // as we just need right side view
        // preorder: rootLR
        // reverse preorder: RLroot
        // so we go through all levels and push the right nodes first
        int level=0;
        vector<int> res;
        revPreorder(root, level, res);
        return res;
    }
};