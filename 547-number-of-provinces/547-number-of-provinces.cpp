class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &vis, int node)
    {
        vis[node]=1;
        // we now check the connections within the list and then traverse those adj nodes
        // we check the adj only for the nodes who are connetced ie have 1 as the value
        for(int i=0; i<isConnected[node].size(); i++)
        {
            // we do DFS only if that node is connected and not visited
            if(isConnected[node][i]==1 && !vis[i])
            {
                dfs(isConnected, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // we need to traverse and check if theres any connected component
        // we have to basically find the no of different components in the graph
        // like for example 1: [[1,1,0],[1,1,0],[0,0,1]]
        // its an adj list:
        /* Nodes:  1  2  3
        Node: 1 -> 1  1  0
        Node: 2 -> 1  1  0
        Node: 3 -> 0  0  1
        1=connected and 0=connected
        we just need to return the no of groups
        */
        // lets peform a DFS
        int nodes=isConnected.size();
        // we peform a DFS on every node
        vector<int> vis(nodes, 0);
        int ans=0;
        for(int i=0; i<nodes; i++)
        {
            if(!vis[i])
            {
                dfs(isConnected, vis, i);
                ans++;
            }
        }
        return ans;
    }
};