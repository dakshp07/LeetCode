class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // All nodes with no in-degree must in the final result, because they can not be reached from. All other nodes can be reached from any other nodes
        // All other nodes can be reached from some other nodes.
        // so no matter what our ans always contains the node which do not have any indegree
        // so we just need to push those nodes but for that we make an adj list first
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        // calculating indegree
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        // push all nodes with indegree as 0
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0) res.push_back(i);
        }
        return res;
    }
};