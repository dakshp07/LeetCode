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
    void inorder(TreeNode* root, vector<int> &ans)
    {
        // inorder: LrootR
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        // an inorder of bst is always sorted
        // so we can do an inorder store it in vector and peform a bs on it
        // the other way could be to use bst iterator (done in previous submission)
        // we try inorder one
        vector<int> arr;
        inorder(root, arr);
        int left=0, right=arr.size()-1;
        while(left<right)
        {
            if(arr[left]+arr[right]==k) return true;
            if(arr[left]+arr[right]<k) left++;
            else right--;
        }
        return false;
    }
};