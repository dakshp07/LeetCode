class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // its similar to the course schedule 1 where we see if the cycle is there
        // we used topo sort and checked if cnt==no of nodes and returned true/false accordingly
        // now we will again use topo sort to check cycle if cycle is there we return empty array
        // if no cycle we return arr
        vector<int> res;
        queue<int> q;
        // pre[1] (v) is the req course, so pre [0] (u) is dependent on v 
        // edge: v->u
        // no of nodes=numCourses
        vector<int> adj[numCourses]; // adj list
        // indegree
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int cnt=0; // if cnt==no of nodes we will say there's a cycle and return empty arr
        // else we push all ele from queue to arr and return arr
        // start looking for other nodes
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            // add the node to our res
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
        // if cycle does not exists then we return the order
        if(cnt==numCourses) return res;
        // else empty arr
        return {};
    }
};
