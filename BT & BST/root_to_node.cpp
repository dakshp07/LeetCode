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
    bool inorder(TreeNode *node, vector<int> &res, int target)
    {
        if(node==NULL) return false;
        // we push root
        res.push_back(node->val);
        // if we reach target means return
        if(node->val==target) return true;
        // we keep looking for stuffs on left and right
        if(inorder(node->left, res, target) || inorder(node->right, res, target)) return true;
        // pop back in case we get false
        res.pop_back();
        return false;
    }
    vector<int> binaryTreePaths(TreeNode* root) {
        // we will find path using preorder traversal
        // we go to left and right
        // and store the unqiue, not null values in ds
        // our recursive calls are first made to left and then to right
        vector<int> res;
        if(root==NULL) return res;
        inorder(root, res, target);
        return res;
    }
};
