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
    TreeNode* bstMaker(vector<int>& nums, int left, int right)
    {
        // base case is similar to base case of bs
        if(left>right) return NULL;
        // now we find mid
        int mid=(left+right)/2;
        // so our root node ie head will be the num at pos mid
        TreeNode *root=new TreeNode(nums[mid]);
        // now left side of bst is nums less than root
        // and right side has all nums greater than root
        // so we assign all nodes on left of root from range of pos [left, mid-1]
        root->left=bstMaker(nums, left, mid-1);
        // and right nodes will be assigned from range of pos [mid+1, right]
        root->right=bstMaker(nums, mid+1, right);
        // return root node
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // we use bs to create the tree
        // base case: if our nums is empty
        if(nums.size()==0) return NULL;
        TreeNode* root=bstMaker(nums, 0, nums.size()-1);
        return root;
    }
};