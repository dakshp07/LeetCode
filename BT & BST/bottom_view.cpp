class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // we follow an approac similar to the top view
        // in top view we add a new node to a line if not present already
        // but in the bottom view we replace the old ones with new ones
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            // in top view we had an if condition, if theres nothing for that line we add
            mp[line]=node->data; // in bottom view we keep the last one
            // lets go to left, right nodes
            if(node->left!=NULL) q.push(make_pair(node->left, line-1));
            if(node->right!=NULL) q.push(make_pair(node->right, line+1));
        }
        for(auto it: mp) ans.push_back(it.second);
        return ans;
    }
};
