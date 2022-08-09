class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // we will use Dijkstra algo to find the shortest path
        // we also need to build the adj list
        vector<pair<int, int>> adj[n+1]; // store the edge u->v and the time
        for(int i=0; i<times.size(); i++)
        {
            /*
                w
            u ----> v
            we store them accordingly in our adj list
            */
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n+1, INT_MAX); // dis is essentially the time taken to reach ith node
        pq.push({0, k}); // 0 dis as k is our src node
        dis[k]=0; // as this is our src node
        while(!pq.empty())
        {
            int prev=pq.top().second;
            pq.pop();
            for(auto it: adj[prev])
            {
                int next_node=it.first;
                int next_dis=it.second;
                if(dis[next_node]>dis[prev]+next_dis)
                {
                    dis[next_node]=dis[prev]+next_dis; // update dis
                    pq.push({dis[next_node], next_node}); // and push into queue
                }
            }
        }
        // now we pick max value of all ans in dis array as ans
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            // if there are still some node as INT_MAX distance we return -1
            // because we never reach them
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans, dis[i]); // in other cases we max our ans
        }
        return ans;
    }
};