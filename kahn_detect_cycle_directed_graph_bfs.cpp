// Kahn's Algo
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // we will use the Kahn's Algo
        // since kahn's algo can create a topo order which exists only for a DAG
        // we try to generate a topo sort for this graph and if we were unable to generate one we return true that it has an cycle
        queue<int> q;
        vector<int> res;
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        // we keep a cnt of nodes
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            // everytime we pop we get an ele
            // so we increment cnt
            cnt++;
            res.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        // if we have a topo sort then the cnt==no of vertex V
        if(cnt==V) return false;
        return true;
    }
};
