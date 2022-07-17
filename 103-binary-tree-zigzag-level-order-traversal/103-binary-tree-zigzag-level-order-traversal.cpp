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
        // code will be similar to the normal level order traversal
        // just add a flag to make sure that the zig zag order is maintained
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans; // if we aint have any node
        bool flag=true; // if its true we will put node from L->R, if its false we put from R->L
        // push the root
        q.push(root);
        while(!q.empty())
        {
            // now lets see the left and right child
            int sz=q.size();
            vector<int> levels(sz); // as we will be accessing the indexes on the basis of flag
            for(int i=0; i<sz; i++)
            {
                TreeNode *node=q.front();
                q.pop();
                // if its true we add on ith index or else we add on size-1 index ie size-1-i
                int index=(flag) ? i : sz-1-i;
                // add the node to our level
                levels[index]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);   
            }
            // change flag
            flag=!flag;
            ans.push_back(levels);
        }
        return ans;
    }
};