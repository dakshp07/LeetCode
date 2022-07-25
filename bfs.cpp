class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        vector<int>res;
      // if we have multiple components then we do:
      /*
      for(int i=1;i<=V; i++)
      {
      if(!vis[i])
      {
      queue<int> q;
      q.push(i);
      vis[i]=1;
      ....... so on
      }
      */
           if (!vis[0]){
                queue<int>q;
                q.push(0);
                vis[0] = 1;
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    res.push_back(x);
                    for (auto f:adj[x]){
                        if (!vis[f]){
                            q.push(f);
                            vis[f]=1;
                        }
                    }
              }
        }
        return res;
    }
};
