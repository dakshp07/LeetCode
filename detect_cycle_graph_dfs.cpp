class Solution {
  public:
  bool cycle(vector<int> adj[], int parent, int i, vector<int> &vis)
  {
      vis[i]=1; // mark the current vertex as 1 in visited array
      for(auto it: adj[i])
      {
          if(!vis[it])
          {
              // we update the parent, node and call cycle func recursively
              if(cycle(adj, i, it, vis))          
              {
                  return true; // if we found  cycle we return from here
              }
              else if(it!=parent) // if the parent isnt equal to the index of vertex
              {
                  // means we found a cycle
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // before we tried using BFS now we see DFS
        vector<int> vis(V+1, 0);
        for(int i=1; i<=V; i++)
        {
            if(!vis[i])
            {
                if(cycle(adj, -1, i, vis)) return true;
            }
        }
        return false;
    }
};
