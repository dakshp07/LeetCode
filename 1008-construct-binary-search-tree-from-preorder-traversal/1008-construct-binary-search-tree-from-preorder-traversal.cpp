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
    TreeNode *build(vector<int> &arr, int &i, int ub)
    {
        // i is the iterator over a which is our preorder array
        if(i==arr.size() || arr[i]>ub) return NULL; // if we run out of ele or if any ele is > ub we return null
        TreeNode *root=new TreeNode(arr[i]); // if not out of bound we take it and take that as root
        i++; // for next ele
        // now left root will be contructed by taking our root as ub
        root->left=build(arr, i, root->val);
        // now right root will be contructed by taking the same ub
        root->right=build(arr, i, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // we use the concept of range from Valid BST
        // we keep an upper bound (ub) for every node and update it as we move ahead
        int i=0;
        return build(preorder, i, INT_MAX);
    }
};