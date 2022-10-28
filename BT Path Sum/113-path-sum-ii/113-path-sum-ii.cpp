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
    vector<vector<int>> ans;
    void checkPath(TreeNode* root, int targetSum, vector<int> &path)
    {
        // if root==NULL we return
        if(root==NULL) return;
        // now we add this node to path vector as it could be a potential node
        path.push_back(root->val);
        // reduce the targetSum
        targetSum-=root->val;
        // now we check the nodes if they are leaf or not
        if(root->right==NULL && root->left==NULL)
        {
            // now we see if we can really add this to ans vector
            // we check the path is correct by seeing if targetSum becomes 0
            if(targetSum==0) ans.push_back(path);
        }
        else
        {
            // now as we have not reached leaf node we call for right,left subtree
            checkPath(root->right, targetSum, path);
            checkPath(root->left, targetSum, path);
        }
        // we backtrack after every recursive call
        path.pop_back();
    };
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // so we can have multiple paths
        // we call recursively for all left,right subtree
        vector<int> path;
        checkPath(root, targetSum, path);
        return ans;
    }
};