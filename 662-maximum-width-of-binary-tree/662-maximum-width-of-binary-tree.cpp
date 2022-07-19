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
    int widthOfBinaryTree(TreeNode* root) {
        // we index the tree to get the max width
        if(root==NULL) return 0;
        queue<pair<TreeNode *, int>> q;
        int ans=0;
        q.push(make_pair(root, 0)); // root node has an index of 0
        while(!q.empty())
        {
            int sz=q.size();
            int min_ind=q.front().second; // index
            int first, last; // the first and last indexes
            for(int i=0; i<sz; i++)
            {
                long curr_ind=q.front().second-min_ind; // the curr node's index, we remove min to make sure that index doesnt overflows
                TreeNode *node=q.front().first; // the curr node
                q.pop(); // pop from the queue
                // if we are at first index
                if(i==0) first=curr_ind;
                // if we are at last index
                if(i==sz-1) last=curr_ind;
                // we carry on the traversal on left side
                if(node->left!=NULL) q.push(make_pair(node->left, curr_ind*2+1)); // the left side index is calculated using formula 2*curr+1
                if(node->right!=NULL) q.push(make_pair(node->right, curr_ind*2+2)); // the right side index is calculated using formula 2*curr+2
            }
            // the index formula for width
            ans=max(ans, last-first+1);
        }
        return ans;
    }
};