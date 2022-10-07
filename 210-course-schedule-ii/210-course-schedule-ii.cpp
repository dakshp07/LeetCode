class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // so in course schedule I we find out if theres a cycle or not
        // we did that using kahn's algo and bfs
        // here we need to return the order in which the courses should be taken
        // for this we use topo sort but we need the graph first ie adj list
        
        /*
        for any course: [i, j] j is the pre of i
        so i is dependent on j
        j->i this is the direction of graph because i can take place after j
        now we create the adj list
        */
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        for(int i=0; i<n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // now for topo sort we need indegree
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<n; i++)
        {
            // indegree will of just i since the direction in graph is j->i
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        // next step is to push all the nodes with indgree==0 in queue
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        // next is to peform BFS
        // but we check for a cycle too, since if there's a cycle then we have to return {}
        int cnt=0;
        vector<int> res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            cnt++;
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return res;
        return {};
    }
};
