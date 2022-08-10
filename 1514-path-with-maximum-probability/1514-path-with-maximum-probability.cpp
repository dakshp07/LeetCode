class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // we can use Dijkstra algo for this
        vector<pair<int, double>> adj[n];
        for(int i=0; i<edges.size(); i++)
        {
            /*
                w
            u------->v
            u is edges[i][0], v is edges[i][1] and w is the succesProb
            */
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]}); // as its undirected
        }
        // Dijkstra
        // {prob, node} in pq
        priority_queue<pair<double, int>> pq; // no min heap as we need max value for the ans
        vector<double> dis(n, 0); // dis is the probablity to reach ith node we start from 0
        pq.push({1.0, start}); // the prob to reach start is 1
        dis[start]=1; // to reach src
        while(!pq.empty())
        {
            double curr_prob=pq.top().first;
            int curr_node=pq.top().second;
            pq.pop();
            for(auto it: adj[curr_node])
            {
                int new_node=it.first;
                double new_prob=it.second;
                if(curr_prob*new_prob>dis[new_node]) // the prob gets multiplied
                {
                    dis[new_node]=curr_prob*new_prob;
                    pq.push({dis[new_node], new_node});
                }
            }
        }
        return dis[end];
    }
};