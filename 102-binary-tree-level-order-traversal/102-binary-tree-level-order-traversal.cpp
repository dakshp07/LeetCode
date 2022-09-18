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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // in order to peform a level order we need to do a bfs
        // in bfs we use queue to make sure that fifo order is maintained
        if(root==NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root); // start with root
        // we iterate till the queue is empty
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> lvl;
            // we iterate over the size of queue as we have to see for all nodes
            for(int i=0; i<sz; i++)
            {
                // pick the node and pop it from queue
                TreeNode *node=q.front();
                q.pop();
                // if they have childs then push those child to queue so that they can be next
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                // this will now complete our one level
                lvl.push_back(node->val);
            }
            // we now push this level to our ans
            res.push_back(lvl);
        }
        return res;
    }
};