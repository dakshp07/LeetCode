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
    // let get left height
    int left_height(TreeNode *root)
    {
        int height=0;
        while(root!=NULL)
        {
            height++; // increment height
            root=root->left; // go to next left
        }
        return height;
    }
    // let get right height
    int right_height(TreeNode *root)
    {
        int height=0;
        while(root!=NULL)
        {
            height++; // increment height
            root=root->right; // go to next right
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        // we go to right subtree and left subtree to get their no of nodes
        // once we got those two values
        // the formula for total no of nodes in complete BT is (2^h-1)
        if(root==NULL) return 0;
        int lh=left_height(root); // get left subtree height
        int rh=right_height(root); // get right subtree height
        if(lh==rh) return pow(2, lh)-1; // if left height and right height are same then we got the ans
        // else we add the individual count of nodes from the subtrees left and right and then add +1 to final ans
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};