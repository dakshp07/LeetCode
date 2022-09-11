class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // we use the concept of partition dp
        /*
        recursion:
        int func(int i, int j)
        {
        if(i>j) return 0;
        int mini=INT_MAX;
        for(int k=i; k<j; k++)
        {
        int cost=cuts[j+1]-cuts[i-1]+func(i, k-1)+func(k+1, j);
        mini=min(mini, cost);
        }
        return mini;
        }
        
        memoization:
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int func(int i, int j)
        {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>j) return 0;
        int mini=INT_MAX;
        for(int k=i; k<j; k++)
        {
        int cost=cuts[j+1]-cuts[i-1]+func(i, k-1)+func(k+1, j);
        mini=min(mini, cost);
        }
        return dp[i][j]=mini;
        }
        */
        // tabulation:
        int N=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        for(int i=N; i>=1; i--)
        {
            for(int j=1; j<=N; j++)
            {
                // base case
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i; k<=j; k++)
                {
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini, cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N];
    }
};