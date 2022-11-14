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
    void path(TreeNode* root, int targetSum, vector<int> &paths, vector<vector<int>> &ans)
    {
        // base case: if we reach end we return function call
        if(root==NULL) return;
        // now if we pick current node, means next we need to look for targetSum-root->val
        // and also the current node could be in our paths
        targetSum-=root->val;
        paths.push_back(root->val);
        // a path is completed when we reach last nodes ie nodes with no child
        if(root->right==NULL && root->left==NULL)
        {
            // this means we are in our last nodes
            // now we push path to ans if the targetSum becomes 0
            if(targetSum==0)
            {
                ans.push_back(paths);
            }
        }
        // if we are not at last nodes, we keep on looking
        else
        {
            // now we go right, left;
            path(root->right, targetSum, paths, ans);
            path(root->left, targetSum, paths, ans);
        }
        // now when we get back we need to pop this node off, ie backtracking
        paths.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // so we go through the left,right side of tree
        // and see if there is any path
        vector<int> paths;
        vector<vector<int>> res;
        path(root, targetSum, paths, res);
        return res;
    }
};