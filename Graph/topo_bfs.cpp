// Kahn's Algo
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // we try to use BFS now, using kahn's algo
	    // an indegree arrays will store the indegree of every node
	    // a queue will be used to store the nodw with indegree as zero
	    queue<int> q;
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++; // store indegree
	        }
	    }
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i]==0) // push all the node with indegree as 0
	        {
	            q.push(i);
	        }
	    }
	    vector<int> res;
	    // BFS Code
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        res.push_back(node);
	        for(auto it: adj[node])
	        {
	            indegree[it]--; // -1 the indegree
	            if(indegree[it]==0)
	            {
	                q.push(it); // if indegree is zero we push to queue
	            }
	        }
	    }
	    return res;
	}
};
