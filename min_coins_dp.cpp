int minimumElements(vector<int> &num, int x)
{
    // so we use recursion and check all the combination
    /*
    // recursion: tc: O(2^n) and sc: O(n)
    // func(ind, target) means the no of coins that ive had at index ind with a max target of target
    int func(int ind, int target)
    {
    // base case
    if(ind==0)
    {
    // we see if that coin can be picked up or not ie target%coins[i]==0
    // if yes then we add the count ie target/coins[i]
    if(target%coins[i]==0) return target/coins[i];
    else return 1e9;
    }
    int not_take=0+func(ind-1, target);
    // we initial take as max as we need min
    int take=INT_MAX;
    if(coins[ind]<=target) take=1+func(ind, target-coins[ind]); // as we can pick same coin again and again 
    return min(take, not_take);
    }
    
    // memoization: tc: O(n*target) and sc: O(n*target) and O(n)
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    int func(int ind, int target)
    {
    // base case
    if(ind==0)
    {
    if(dp[ind][target]!=-1) return dp[ind][target];
    // we see if that coin can be picked up or not ie target%coins[i]==0
    // if yes then we add the count ie target/coins[i]
    if(target%coins[i]==0) return target/coins[i];
    else return 1e9;
    }
    int not_take=0+func(ind-1, target);
    // we initial take as max as we need min
    int take=INT_MAX;
    if(coins[ind]<=target) take=1+func(ind, target-coins[ind]); // as we can pick same coin again and again 
    return dp[ind][target]=min(take, not_take);
    }
    */
    // tabulation:
    int n=num.size();
    int target=x;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    // base case
    // if ind==0
    for(int t=0; t<=target; t++)
    {
        if(t%num[0]==0)
        {
            dp[0][t]=t/num[0];
        }
        else
        {
            dp[0][t]=1e9;
        }
    }
    // for loops
    for(int ind=1; ind<n; ind++)
    {
        for(int t=0; t<=target; t++)
        {
            int not_take=0+dp[ind-1][t];
            int take=INT_MAX;
            if(num[ind]<=t) 
            {
                take=1+dp[ind][t-num[ind]]; 
            }
            dp[ind][t]=min(take, not_take);   
        }
    }
    int ans=dp[n-1][target];
    if(ans>=1e9) return -1;
    return ans;
}
