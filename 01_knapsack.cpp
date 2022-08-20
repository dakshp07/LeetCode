int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // as we all know that greedy solution doesnt works for knapsack
    // so we try out all the possible combinations among the given inputs
    // and then return the best ones
    /*
    recursion: tc: O(2^n) and sc: O(n)
    // we take two parameters to work around ie ind, maxWeight
    // explore all possibilities, pick and not pick
    // pick max one
    // func(int ind, int W) means till index ind what max value you can get with the max wt being W
    int func(int ind, int W)
    {
    // base case will be at 0 as we start from n-1
    if(ind==0)
    {
    // now if the theif still has space in bag he adds this ind as well
    if(weight[ind]<=W) return value[ind];
    else return 0;
    }
    // at any index the thief can either pick or non pick
    int not_pick=0+func(ind-1, W);
    int pick=INT_MIN; // as we need to maximize
    if(weight[ind]<=W) pick=value[ind]+func(ind-1, W-weight[ind]);
    return max(pick, not_pick);
    }
    
    // memoization: tc: O(n*w) and sc: (n*w) for array + O(n) for stack space
    // (ind, wt) as the dp array
    vector<vector<int>> dp(n, vector<int>(W+1));
    int func(int ind, int W)
    {
    if(dp[ind][W]!=-1) return dp[ind][W]; 
    // base case will be at 0 as we start from n-1
    if(ind==0)
    {
    // now if the theif still has space in bag he adds this ind as well
    if(weight[ind]<=W) return value[ind];
    else return 0;
    }
    // at any index the thief can either pick or non pick
    int not_pick=0+func(ind-1, W);
    int pick=INT_MIN; // as we need to maximize
    if(weight[ind]<=W) pick=value[ind]+func(ind-1, W-weight[ind]);
    return dp[ind][W]=max(pick, not_pick);
    }
    */
    // tabulation:
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    // base case
    // if ind==0, we can pick from wt[0] to maxwt being W
    for(int W=weight[0]; W<=maxWeight; W++)
    {
        // all of the ind==0 will grab the value of ind ie 0
        dp[0][W]=value[0];
    }
    // transition
    for(int ind=1; ind<n; ind++)
    {
        for(int W=0; W<=maxWeight; W++)
        {
            int not_pick=0+dp[ind-1][W];
            int pick=INT_MIN; // as we need to maximize
            if(weight[ind]<=W) pick=value[ind]+dp[ind-1][W-weight[ind]];
            dp[ind][W]=max(pick, not_pick);
        }
    }
    return dp[n-1][maxWeight];
}
