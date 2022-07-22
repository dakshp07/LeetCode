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
    TreeNode* searchBST(TreeNode* root, int val) {
        // we will use the property of BST ie left<node and right>node
        // we will traverse till we each end and dont find our ans
        while(root!=NULL && root->val!=val)
        {
            // if(val>root->val)
            // {
            //     // our target is bigger than root
            //     root=root->right;
            // }
            // if(val<root->val)
            // {
            //     // our target is smaller than root
            //     root=root->left;
            // }
            root=root->val>val ? root->left : root->right;
        }
        return root;
    }
};