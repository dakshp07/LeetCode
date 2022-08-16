bool subsetSumToK(int n, int k, vector<int> &arr) {
    // we can use recursion to form all the subsets and check them with the target
    /*
    // recursion: tc: O(2^n) and sc: O(n) for stack space
    func(ind, target): means the the ele from (0 to ind) form the target
    int func(inr ind, int target)
    {
    if(target==0) return true; // if we got the ele that sum to target
    if(ind==0) return (arr[0]==target); // if we at 0 index and the arr ele is equal to target
    bool not_take=func(ind-1, target); // we dont pick that ele and then reduce the window from (0 to ind) to (0 to ind-1)
    bool take=false; // intialize
    // now we check arr[ind]<=target then we take it or else we dont
    if(target>=arr[ind]) take=func(ind-1, target-arr[ind]) // as we take it and move back by one index
    return (take || not_take); // as we just need one of them to be true 
    }
    
    // memoization: tc: O(n*target) sc: O(n*target) and O(n) for stack space
    // our states are index, target
    vector<vector<int>> dp(10^3+1, vector<int>(10^3+1)); // dp[ind][target]
    int func(inr ind, int target)
    {
    if(target==0) return true; // if we got the ele that sum to target
    if(ind==0) return (arr[0]==target); // if we at 0 index and the arr ele is equal to target
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool not_take=func(ind-1, target); // we dont pick that ele and then reduce the window from (0 to ind) to (0 to ind-1)
    bool take=false; // intialize
    // now we check arr[ind]<=target then we take it or else we dont
    if(target>=arr[ind]) take=func(ind-1, target-arr[ind]) // as we take it and move back by one index
    return dp[ind][target]=(take || not_take); // as we just need one of them to be true 
    }
    */
    // tabulation: tc: O(n*target) sc: O(n*target) for array
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0)); // dp[ind][target]
    // base case
    // for target to become 0 we can have all the indexes
    for(int i=0; i<n; i++)
    {
        dp[i][0]=true;
    }
    // if i can form a target at 0th index
    dp[0][arr[0]]=true;
    // for loops
    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=k; target++)
        {
            bool not_take=dp[ind-1][target]; // we dont pick that ele and then reduce the window from (0 to ind) to (0 to ind-1)
            bool take=false; // intialize
    // now we check arr[ind]<=target then we take it or else we dont
            if(target>=arr[ind]) take=dp[ind-1][target-arr[ind]]; // as we take it and move back by one index
            dp[ind][target]=(take || not_take); // as we just need one of them to be true 
        }
    }
    return dp[n-1][k]; // for last index with k as target
}
