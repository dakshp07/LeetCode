int findWays(vector<int> &nums, int tar)
{
    // recursion: tc: O(2^n) and sc: O(n)
    /*
    int func(int ind, int target)
    {
    // because the target becoming 0 gives one way ie when we dont pick any ele from arr
    if(target==0) return 1;
    if(ind==0) return (arr[ind]==target);
    int not_pick=func(ind-1, target);
    int pick=0;
    if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
    return pick+not_pick; // as we need total ways and not the bool
    }
    
    // memoization: tc: O(n*sum) sc: O(n*sum) for array and sc: O(n) for stack space
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    int func(int ind, int target)
    {
    if(dp[ind][target]!=-1) return dp[ind][target]
    // because the target becoming 0 gives one way ie when we dont pick any ele from arr
    if(target==0) return 1;
    if(ind==0) return (arr[ind]==target);
    int not_pick=func(ind-1, target);
    int pick=0;
    if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
    return dp[ind][target]=pick+not_pick; // as we need total ways and not the bool
    }
    */
    // tabulation:
    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    // base cases
    // when sum==0
    for(int i=0; i<n; i++)
    {
        dp[i][0]=1;
    }
    // when ind==0
    if(nums[0]<=tar) dp[0][nums[0]]=1;
    // for loops
    for(int ind=1; ind<n; ind++)
    {
        for(int target=0; target<=tar; target++)
        {
            int not_pick=dp[ind-1][target];
            int pick=0;
            if(nums[ind]<=target) pick=dp[ind-1][target-nums[ind]];
            dp[ind][target]=pick+not_pick;
        }
    }
    return dp[n-1][tar];
}
