int countPartitions(int n, int d, vector<int> &arr) {
    // so we need to find two subsets with sum s1, s2 such that s1>s2 and s1-s2=D
    // so lets say total_sum=s1+s2 (as we need two subsets of entire array)
    /*
    so, s1=total_sum-s2
    total_sum-s2-s2=D
    total_sum-2*s2=D
    s2=(total_sum-D)/2
    // so we need to look for subsets whose sum is (total_sum-D)/2 which becomes our target
    
    // recursion: tc: O(2^n) and sc: O(n)
    int func(int ind, int target)
    {
    if(target==0) return 1;
    if(ind==0) return (arr[ind]==target);
    int not_pick=func(ind-1, target);
    int pick=0;
    if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
    return pick+not_pick;
    }
    
    // memoization: tc: O(n*sum) sc: O(n*sum) for array and sc: O(n) for stack space
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    int func(int ind, int target)
    {
    if(dp[ind][target]!=-1) return dp[ind][target]
    if(target==0) return 1;
    if(ind==0) return (arr[ind]==target);
    int not_pick=func(ind-1, target);
    int pick=0;
    if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
    return  dp[ind][target]=pick+not_pick;
    }
    */
    // tabulation:
    int target=0, sum=0;
    for(int i=0; i<n; i++) sum+=arr[i];
    if((sum-d)%2!=0 || (sum-d)<0) return false;
    target=(sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    // base case
    // when target==0
    for(int i=0; i<n; i++)
    {
        dp[i][0]=1;
    }
    // when target==0
    if(arr[0]<=target) dp[0][arr[0]]=1;
    // for loops
    for(int ind=1; ind<n; ind++)
    {
        for(int curr=0; curr<=target; curr++)
        {
            int not_pick=dp[ind-1][curr];
            int pick=0;
            if(arr[ind]<=curr) pick=dp[ind-1][curr-arr[ind]];
            dp[ind][curr]=pick+not_pick;
        }
    }
    return dp[n-1][target];
}


