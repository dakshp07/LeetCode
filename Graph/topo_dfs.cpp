class Solution
{
	public:
	void dfs(vector<int> adj[], int node, vector<int> &vis, stack<int> &order)
	{
	    vis[node]=1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(adj, it, vis, order);
	        }
	    }
	    order.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // we will do this using dfs
	    // we will push ele on stack which will maintain our order for topo sort
	    vector<int> vis(V, 0); // we use v instead of v+1 as we have 0 based indexing in this graph
	    vector<int> res;
	    stack<int> order;
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, i, vis, order);
	        }
	    }
	    while(!order.empty())
	    {
	        res.push_back(order.top());
	        order.pop();
	    }
	    return res;
	}
};
