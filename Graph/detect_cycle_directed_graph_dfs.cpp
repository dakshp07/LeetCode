class Solution {
  public:
    bool cycle(vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis, int node) 
    {
        vis[node]=1;
        dfs_vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(cycle(adj, vis, dfs_vis, it)) return true; // we call recusively on the adj node if its not visited
            }
            else if(dfs_vis[it]) // if its vis==1 and dfs_vis==1 then we got cycle
            {
                return true; // return true in that case
            }
        }
        dfs_vis[node]=0; // we mark that node as 0 as we are done with dfs call
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        /// we will use two arrays
        // one is standard vis array and the other one is dfs_vis
        // the dfs_vis will keep a track of the nodes we visited in the same recursive call
        // if at any point we see an node as visitd in both the arrays then we have to return true
        vector<int> vis(V+1, 0), dfs_vis(V+1, 0);
        for(int i=1; i<=V; i++)
        {
            if(!vis[i])
            {
                if(cycle(adj, vis, dfs_vis, i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
