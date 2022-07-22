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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // we will try to add the node in the leaf node
        if(root==NULL) return new TreeNode(val); // return node once we get position
        TreeNode *curr=root;
        while(true)
        {
            if(curr->val<=val)
            {
                // if curr < val means go in right side
                // we check if left isnt null
                if(curr->right!=NULL) curr=curr->right;
                // if it isnt null we update the ans
                else
                {
                    // if it isnt null means we need to go to left
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            // if val < curr
            else
            {
                // to left side
                // if curr < val means go in left side
                // we check if left isnt null
                if(curr->left!=NULL) curr=curr->left;
                // if it isnt null we update the ans
                else
                {
                    // if it isnt null means we move left
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};