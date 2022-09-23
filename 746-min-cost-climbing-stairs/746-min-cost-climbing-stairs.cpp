class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // we can explore all possibilities by using recursion
        // and then we try to identify subproblems and use memoization to remove them
        // and then tabulation will help in reducing the tc
        /*
        recursion: tc: O(2^n) and sc: O(n)
        int func(int ind)
        {
        // base case:
        // if we reach our end goal then we return the cost of the those steps
        if(ind==0 || ind==1) return cost[ind];
        // computation:
        int one_step=cost[ind]+func(ind-1);
        int two_step=cost[ind]+func(ind-2);
        return min(one_step, two_step);
        }
        
        memoization: tc: O(n) and sc: O(n)+O(n)
        vector<int> dp(1001, -1);
        int func(int ind)
        {
        if(dp[ind]!=-1) return dp[ind];
        // base case:
        // if we reach our end goal then we return the cost of the those steps
        if(ind==0 || ind==1) return cost[ind];
        // computation:
        int one_step=cost[ind]+func(ind-1);
        int two_step=cost[ind]+func(ind-2);
        return min(one_step, two_step);
        }
        */
        // tabulation: tc: O(n) and sc: O(n)
        // int n=cost.size();
        // vector<int> dp(1001, 0);
        // base case
        // dp[0]=cost[0];
        // dp[1]=cost[1];
        // for loops
        // for(int ind=2; ind<n; ind++)
        // {
        //     int one_step=cost[ind]+dp[ind-1];
        //     int two_step=cost[ind]+dp[ind-2];
        //     dp[ind]=min(one_step, two_step);
        // }
        // since we can either take one step or two step we return min
        // return min(dp[n-1], dp[n-2]);
        
        // space optmise: tc: O(n) and sc: O(1)
        int n=cost.size();
        int prev1=cost[0];
        int prev2=cost[1];
        for(int ind=2; ind<n; ind++)
        {
            int one_step=cost[ind]+prev1;
            int two_step=cost[ind]+prev2;
            int curr=min(one_step, two_step);
            prev1=prev2;
            prev2=curr;
        }
        return min(prev1, prev2);
    }
};
