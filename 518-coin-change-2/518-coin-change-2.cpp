class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // the only change here is that we can use a single coin multiple times
        /*
        recursion: tc: O(2^n) and sc: O(target)
        int func(int ind, int target)
        {
        if(ind==0)
        {
        // one of the case is when the coins[ind] ie coins[0] is equal to target in that case we return 1
        if(coins[ind]==target) return 1;
        // else we return 0
        return 0;
        }
        int not_take=func(ind-1, target);
        int take=0;
        if(coins[ind]<=target) take=func(ind, target-coins[ind]);
        return take+not_take;
        }
        
        // memoization: tc: O()
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int func(int ind, int target)
        {
        if(dp[ind][target]!=-1) return dp[ind][target];
        if(ind==0)
        {
        // one of the case is when the coins[ind] ie coins[0] is equal to target in that case we return 1
        if(coins[ind]==target) return 1;
        // else we return 0
        return 0;
        }
        int not_take=func(ind-1, target);
        int take=0;
        if(coins[ind]<=target) take=func(ind, target-coins[ind]);
        return dp[ind][target]=take+not_take;
        }
        */
        // tabulation:
        int n=coins.size();
        int target=amount;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // base case
        // when ind==0
        for(int t=0; t<=target; t++)
        {
            dp[0][t]=(t%coins[0]==0);
        }
        // for loops
        for(int ind=1; ind<n; ind++)
        {
            for(int t=0; t<=target; t++)
            {
                long not_take=dp[ind-1][t];
                long take=0;
                if(coins[ind]<=t) take=dp[ind][t-coins[ind]];
                dp[ind][t]=take+not_take;
            }
        }
        return dp[n-1][target];
    }
};