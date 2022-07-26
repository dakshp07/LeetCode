class Solution {
  public:
  bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        // instead of a normal queue we will use a pair of <node, parent>
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1}); // for starting node
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node}); // its parent we will be the queue's top as its adjacent node
                }
                else if (parent != it) // if its visited and not the parent node means its a loop
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // we peform a BFS but by using a queue which has pair of node, prev
        // where prev is the node from where we reach that node
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
    }
};
