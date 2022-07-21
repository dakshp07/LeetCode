/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // lets mark parents
    void mark_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode* target)
    {
        // lets add them in queue
        queue<TreeNode *> q;
        q.push(root); // add root
        while(!q.empty())
        {
            TreeNode *curr=q.front(); // get the current node
            q.pop();
            // if curr left is not null then we add the curr as curr's left parent
            if(curr->left!=NULL)
            {
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            // if curr right is not null then we add the curr as curr's right parent
            if(curr->right!=NULL)
            {
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // our nodes can also be present in top direction
        // but BST doesnt supports any operation to check parent
        // so we store all parents 
        // and then we also maintain an hash to keep track of visited nodes
        unordered_map<TreeNode *, TreeNode *> parent_track; // map to keep track of parent node
        // call our parent function
        mark_parent(root, parent_track, target);
        unordered_map<TreeNode *, bool> visited; // to keep track of visited nodes
        queue<TreeNode *> q; // for level order traversal
        q.push(target); // instead of pushing root, we push target since thats from where we peform BFS
        visited[target]=true; // since we already visited the target
        int curr_level=0; // current level track
        while(!q.empty())
        {
            // BFS to go to our k th level node
            int sz=q.size();
            if(curr_level++ == k) break; // we start from 0 so we make it 1 first
            // run a loop in queue
            for(int i=0; i<sz; i++)
            {
                TreeNode *curr=q.front(); // get the first node
                q.pop();
                // we then we see if curr left exist and not yet visited
                if(curr->left!=NULL && !visited[curr->left])
                {
                    // we push and add it to visited
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                // we then we see if curr right exist and not yet visited
                if(curr->right!=NULL && !visited[curr->right])
                {
                    // we push and add it to visited
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                // we know check similarly for the current's parent
                if(parent_track[curr] && !visited[parent_track[curr]])
                {
                     // we push and add it to visited
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        // get res from queue
        vector<int> res;
        while(!q.empty())
        {
            TreeNode *curr=q.front(); // get the current node
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};