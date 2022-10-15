class Solution {
public:
    void dfs(vector<int> adj[], vector<int> &vis, int node)
    {
        // mark as visited
        vis[node]=1;
        // now visit all adj nodes and see them too
        for(auto it: adj[node])
        {
            if(!vis[it]) dfs(adj, vis, it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // so essentially we need to find the number of islands
        // but for that we need to know which all cities are connected to whom
        // and then it becomes like a number of islands question
        // so the adj list will contain a node and a list of all nodes that are connected to it
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<isConnected[i].size(); j++)
            {
                if(isConnected[i][j]==1 && i!=j) // i!=j is to make their aint no entries like 1->1 or 2->2
                {
                    adj[i].push_back(j);
                    // since they are bidirectionally connected
                    // we push i->j and j->i
                    adj[j].push_back(i);
                }
            }
        }
        // now we got the adj list
        // and now we run a dfs
        int ans=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            // if not visited we run a dfs
            if(!vis[i])
            {
                dfs(adj, vis, i);
                ans++;
            }
        }
        return ans;
    }
};