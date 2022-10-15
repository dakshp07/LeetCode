class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<int> &vis, int index)
    {
        vis[index]=1;
        for(int i=0; i<stones.size(); i++)
        {
            // stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1]
            // the aboves condition check if ith stones and index stones lies either on same row or same col
            if(!vis[i] && (stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1]))
            {
                dfs(stones, vis, i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        // we can use a dfs or bfs traversal and check out all stones that are on same row or same col
        // if they are on same row we consider them as our ans
        int n=stones.size();
        int cnt=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(stones, vis, i);
                cnt++;
            }
        }
        // we do n-cnt, because cnt contains the group of all ele
        // cnt is essentially the number of islands
        // but here we dont need group, we need ungrouped ones
        // so to get that we subtract group from total
        return n-cnt;
    }
};