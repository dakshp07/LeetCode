void bfs(vector<int> adj[], int V, int src)
{
    vector<int> dis(V, INT_MAX); // intialize all the node dis as INT_MAX
    queue<int> q;
    q.push(src); // push the src into queue
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it: adj[node])
        {
            // since the weight is 1 for every node, and we know the dis b/w src and node (ie dis[node]) we update our dis[node] only if its smaller
            if(dis[node]+1<dis[node])
            {
                dis[it]=dis[node]+1;
                q.push(it); // we also push only the adj nodes whose dis gets updated
            }
        }
    }
    for(auto it: dis) cout<<it<<endl;
}
