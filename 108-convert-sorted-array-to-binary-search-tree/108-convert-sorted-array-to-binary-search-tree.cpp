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
    TreeNode* bstMaker(vector<int> &nums, int low, int high)
    {
        // our base case will be when start>end as thats when we return
        if(low>high) return NULL;
        // now we find the mid
        int mid=(low+high)/2;
        // we call recursively for the part before mid and for part after mid
        TreeNode* head=new TreeNode(nums[mid]);
        // so the left part of tree has the numbers < root
        // so we add the part from [left,mid-1] to left
        head->left=bstMaker(nums, low, mid-1);
        // and add the part from [mid+1,high] to right
        head->right=bstMaker(nums, mid+1, high);
        return head;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // we use binary search to make the bst
        if(nums.size()==0) return NULL;
        TreeNode* head=bstMaker(nums, 0, nums.size()-1);
        return head;
    }
};