// we do using the DFS traversal
// we will be peforming a topo sort as step 1
// and then put all the topo sort in stack and then peform shortest path thing
void topoSort(vector<pair<int, int>> adj[], int node, vector<int> &vis, stack<int> &st)
{
    // here we find the topo sort and push them into a stack
    vis[node]=1; // mark node as visited
    for(auto it: adj[node])
    {
        if(!vis[it.first]) // if not visited node
        {
            topoSort(adj, it.first, vis, st);
        }
    }
    st.push(node);
}
void shortestPath(vector<pair<int, int>> adj[], int src, int V)
{
    vector<int> vis(V, 0);
    stack<int> st; // to store our topo sort in order
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            topoSort(adj, i, vis, st); // we find the topo sort of every not visisted node
        }
    }
    vector<int> dis(V, INT_MAX);
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dis[node]!=INT_MAX) // in order to reach adj node we need to reach its parent node
        {
            for(auto it: adj[node])
            {
                if(dis[node]+it.second<dis[it.first])
                {
                   dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }
    for(auto it: dis) cout<<it<<endl;
}
