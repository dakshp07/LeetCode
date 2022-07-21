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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++) {
            map[inorder[i]] = i;
        }
        
        int idx = postorder.size()-1;
        return splitTree(inorder, postorder, 0, n-1, idx);
    }
    
    TreeNode* splitTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &idx) {
        if(inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[idx--]);
        int mid = map[root->val];
        root->right = splitTree(inorder, postorder, mid+1, inEnd, idx);
        root->left = splitTree(inorder, postorder, inStart, mid-1, idx);
        return root;
    }
};