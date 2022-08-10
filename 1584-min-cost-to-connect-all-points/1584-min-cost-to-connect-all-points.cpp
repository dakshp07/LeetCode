class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // we need to indetify the minimum cost ie we are supposed to build a MST
        // we can use either prim's or kruskal
        // lets use prim's
        // lets create the adj list first
        int n=points.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                // for every point i, j we store their wt ie the manhattan dis
                adj[i][j]=abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        // Prim's algo
        // vector<int> parent(n, -1); not required as we are getting the final cost and not the tree
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        key[0]=0;
        pq.push({0, 0}); // {key, index}
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            mst[u]=true;
            for(int j=0; j<n; j++)
            {
                int v=j;
                int wt=adj[u][j];
                if(mst[v]==false && wt<key[v])
                {
                    // parent[v]=u; not needed as we just need cost to print and not tree
                    key[v]=wt;
                    pq.push({key[v], v});
                }
            }
        }
        int cost=0;
        for(int i=0; i<n; i++)
        {
            cost+=key[i]; // key stores the wt
        }
        return cost;
    }
};
