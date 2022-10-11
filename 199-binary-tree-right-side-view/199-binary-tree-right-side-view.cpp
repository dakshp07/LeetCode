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
    void revpreorder(TreeNode* root, vector<int> &ans, int level)
    {
        if(root==NULL) return;
        // if the level becomes equal to size of vector
        // means now we have again reached a right node
        // so we push it to ans
        if(level==ans.size()) ans.push_back(root->val);
        // recursive calls for other nodes
        revpreorder(root->right, ans, level+1);
        revpreorder(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // so we just need the right side nodes of the tree
        // we do something called the reverse preorder
        // preoder: rootLR
        // reverse preorder: rootRL
        vector<int> ans;
        revpreorder(root, ans, 0);
        return ans;
    }
};