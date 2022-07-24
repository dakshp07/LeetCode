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
    TreeNode *first, *prev, *middle, *last; // nodes
    void inorder(TreeNode *root)
    {
        if(root==NULL) return;
        inorder(root->left);
        // now we check the node variables that we made
        if(prev!=NULL && (root->val<prev->val)) // if nodes violate the order
        {
            // if this is the first violation then we mark them as first and middle
            // with this we cover our case 2.
            if(first==NULL) // check if its first violation by seeing first
            {
                first=prev; // update val
                middle=root;
            }
            // if its not first violation then mark this node as last
            else last=root;
        }
        prev=root; // to cover case 1.
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        // brute force way is to do a postorder and sort it and then compare it with the inorder
        // but we will optimse it: we have 2 cases
        // 1. swap nodes are adjacent: then we do a inorder and keep track of prev if prev>null then we swap
        // 2. swap nodes are not adjacent: then we store the nodes as first, middle and last, swap first and last
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first!=NULL && last!=NULL) // case 2 violation
        {
            swap(first->val, last->val); // swap the nodes if we get the violations
        }
        else if(first!=NULL && middle!=NULL) // case 1 violation
        {
            swap(first->val, middle->val); // swap the nodes if we get the violations
        }
    }
};