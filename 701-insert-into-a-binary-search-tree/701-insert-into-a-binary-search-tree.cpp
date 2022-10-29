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
    TreeNode* insert(TreeNode* root, int val)
    {
        // if we reach end of tree and there's no position for the val node to be added
        // then we add it to end of tree
        if(root==NULL)
        {
            TreeNode* node=new TreeNode(val); // create a new node
            return node; // return new node
        }
        // now if current node val< our new node
        // we go to right as its bigger than our current node
        if(root->val<val)
        {
            root->right=insert(root->right, val);
        }
        // now if current node val> our new node
        // we go on left to see if we can insert it there
        else
        {
            root->left=insert(root->left, val);
        }
        // return our root
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // we recursively go through nodes
        // since its a bst we go left/right accordingly
        return insert(root, val);
    }
};