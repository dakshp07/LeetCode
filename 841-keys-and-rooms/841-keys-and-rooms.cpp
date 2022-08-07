class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // we just need to see if we are visiting all rooms or not
        // so we can do BFS or DFS, lets use a BFS
        // so we have [[1],[2],[3],[]]
        // means we can go to 1 from 0, so 1 is dependent on 0
        // 0->1, 1->2, 2->3
        /*
        [[1,3],[3,0,1],[2],[0]]
        graph: 0->{1, 3}, 1->{3, 0, 1}
        */
        int n=rooms.size(); // no of nodes
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0); // push first room
        vis[0]=1; // mark as visited
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it: rooms[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        // now we see the vis array if any of the node (ie room) isnt true means we havent visited that yet
        // so we return false
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                // means false
                return false;
            }
        }
        return true;
    }
};