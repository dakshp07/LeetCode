int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // in 0/1 knapsack we had limited supply of an specific instance
    // here in ubounded we can pick a specific instance multiple times
    /*
    recursion: func(n-1, W) means the max value i can have till index n-1 with a bag weight of W
    int func(int ind, int W)
    {
    // as on ind==0 he pick that multiple times and take it till its not divisible
    if(ind==0) return ((W/wt[0])*val[0]);
    int not_take=0+func(ind-1, W);
    int take=INT_MIN; // as we need max value
    // we pick only when the wt of current ind is less than W
    if(wt[ind]<=W) take=val[ind]+func(ind, W-wt[ind]);
    return max(take, not_take);
    }
    
    memoization:
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    int func(int ind, int W)
    {
    if(dp[ind][W]!=-1) return dp[ind][W];
    // as on ind==0 he pick that multiple times and take it till its not divisible
    if(ind==0) return ((W/wt[0])*val[0]);
    int not_take=0+func(ind-1, W);
    int take=INT_MIN; // as we need max value
    // we pick only when the wt of current ind is less than W
    if(wt[ind]<=W) take=val[ind]+func(ind, W-wt[ind]);
    return dp[ind][W]=max(take, not_take);
    }
    */
    // tabulation:
    int W=w;
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    // base case
    for(int wt=0; wt<=W; wt++)
    {
        dp[0][wt]=(wt/weight[0])*profit[0];
    }
    for(int ind=1; ind<n; ind++)
    {
        for(int wt=0; wt<=W; wt++)
        {
            int not_take=0+dp[ind-1][wt];
            int take=0; // as we need max value
            // we pick only when the wt of current ind is less than W
            if(weight[ind]<=wt) take=profit[ind]+dp[ind][wt-weight[ind]];
            dp[ind][wt]=max(take, not_take);
        }
    }
    return dp[n-1][W];
}
