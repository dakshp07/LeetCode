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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // code is similar to level order traversal
        // we keep a track with flag, acc to its value we decide if to go from L-R or R-L
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if(root==NULL) return res; // if we aint have any node
        q.push(root);
        bool flag=true; // if its true we will put node from L->R, if its false we put from R->L
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> levels(sz);
            for(int i=0; i<sz; i++)
            {
                auto node=q.front();
                q.pop();
                // if its true we add on ith index or else we add on size-1 index ie size-1-i
                int index=(flag) ? i : sz-1-i;
                levels[index]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            // change flag
            flag=!flag;
            res.push_back(levels);
        }
        return res;
    }
};