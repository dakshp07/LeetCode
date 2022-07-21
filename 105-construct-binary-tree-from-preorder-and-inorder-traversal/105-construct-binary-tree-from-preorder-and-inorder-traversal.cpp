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
    TreeNode * buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map <int,int > &mp) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode * root = new TreeNode(preorder[preStart]);
        int elem = mp[root->val];
        int nElem = elem-inStart;

        root -> left=buildTree(preorder, preStart + 1, preStart + nElem, inorder,
        inStart, elem - 1, mp);
        root -> right=buildTree(preorder, preStart + nElem + 1, preEnd, inorder, 
        elem + 1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // since we have the preorder and inorder
        // we will look for root first and then solve the subtrees on right and left recursively in similar manner
        map<int, int> in; // store the inorder traversal in map
        for(int i=0; i<inorder.size(); i++)
        {
            in[inorder[i]]=i;
        }
        // call build tree recursively for the preorder 
        TreeNode *root=buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, in);
        return root;
    }
};