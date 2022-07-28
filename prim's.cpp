class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	// prims
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // intialize the 3 arrays
        vector<int> parent(V, -1), key(V, INT_MAX); // parent stores the parent of ith node
        // key stores the min weigth of ith node
        vector<bool> mst(V, false); // checks if the ith node is already taking part in making an MST
        
        // a min heap is used to make sure that we take the min wts from all possible adj nodes ie key, index pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push(make_pair(0, 0)); // push the node 0 as we start from there
        key[0]=0; // as we start from there and its wt is 0
        parent[0]=-1; // as we start from there so it has no parent
        
        // we iterate over the edges, as MST has n-1 edges and n nodes
        // so we iterate from 0 to n-1 edges
        for(int cnt=0; i<V-1; i++)
        {
            // we pick the min wt of the edge from min heap
            int u=pq.top().second;
            pq.pop(); // we pop so that the next min goes to top
            mst[u]=true; // since the min wt node is now used in building an MST we set its index as true
            
            // we see the adj nodes now
            for(auto it: adj[u])
            {
                int v=it.first; // node
                int wt=it.second; // weight
                
                // in order to pick the adj node we have to make sure if its not already used in building an MST ie
                // mst[v]== false and that the its weight is less than the wt marked for same node in the key array
                if(mst[v]==false && wt<key[v])
                {
                    // if we follow the condition we push
                    parent[v]=u; // we set its parent as u
                    pq.push(make_pair(key[v], v)); // push the new wt, index
                    key[v]=wt; // update the wt in key as wt is more min
                }
            }
        }
        // we can print mst by traversing through the parent array from 1 to n as 0 is our root
        for(int i=1; i<V; i++)
        {
            cout<<parent[i]<<"-"<<endl;
        }
    }
};
