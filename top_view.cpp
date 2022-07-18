*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // we will use the concept of vertical tree in this
        // we can use a map which stores the (line, node->val) and a queue to store (node, line)
        // the basic idea is if an node on the same line is already present in map, we skip it
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        // we push the root at line 0
        q.push(make_pair(root, 0)); // we start line from root ie at 0
        while(!q.empty())
        {
            // we pop the first ele from our queue
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int line=it.second;
            // now we will see if for this line we have any node already in our map
            // if not there means we add it
            if(mp.find(line)==mp.end())
            {
                // we add the data for that line
                mp[line]=node->data;
            }
            // we do similarly for left and right, if its on right the line is +1 or on right its -1
            if(node->left!=NULL) q.push({node->left, line-1});
            if(node->right!=NULL) q.push({node->right, line+1});
        }
        for(auto it: mp) ans.push_back(it.second);
        return ans;
    }

};
