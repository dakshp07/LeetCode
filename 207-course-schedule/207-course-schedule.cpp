class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // this question is somewhat related to graphs
        // since for every course we have a prerequiste which acts as the adj node for that index
        // and since we have and ordering of the courses ie which course to be done before
        // we can create an adj list for the prerequisites and courses
        // this forms a directed graph
        // this boils down the question to detect a cycle in directed graph
        // we can use DFS or BFS (Kahn's algorithm)
        // i will try to use BFS (Kahn's algorithm) using indegree
        
        // no of courses == no of nodes/vertex
        // prerequisites[1] (v) is the dependency on prerequisites[0] (u) as v is prerequisites of u
        // direction of edge: v->u
        // adj[v]={u1, u2, u3, .....}
        int n=numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n); // our course, its prerequisites
        // we fill indegree first using prerequisites as they have the dependecy of every node
        for(int i=0; i<prerequisites.size(); i++)
        {
            // we also make our adj list
            indegree[prerequisites[i][0]]++; // our node u
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        // push all nodes having an indegree as 0
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        // we start bfs
        int cnt=0; // to keep a track if there is a cycle
        while(!q.empty())
        {
            int node=q.front();
            cnt++;
            q.pop();
            for(auto it: adj[node])
            {
                // check adj node
                indegree[it]--;
                if(indegree[it]==0) q.push(it); // push if indegree is 0
            }
        }
        // if there's a cycle there then no of node will be equal to cnt
        return cnt==n;
    }
};