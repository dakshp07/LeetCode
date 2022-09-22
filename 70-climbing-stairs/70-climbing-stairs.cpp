class Solution {
public:
    int climbStairs(int n) {
        // the total no of distinct ways will be:
        // the no of steps when he takes 1 step each
        // the no of steps when he takes 2 step each
        // so ans is ways(n-1)+ways(n-2)
        // which is what fibonnaci is
        /*
        recursion: tc: O(2^n) and sc: O(n)
        int func(int n)
        {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        return func(n-1)+func(n-2);
        }
        
        memoization: tc: O(n) and sc: O(n)+O(n)
        vector<int> dp(46, -1);
        int func(int n)
        {
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        return dp[n]=func(n-1)+func(n-2);
        }
        */
        // tabulation: O(n) and sc: O(n)
        // vector<int> dp(46, 0);
        // base case
        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;
        // for loop
        // for(int i=3; i<=n; i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        // space optimize: O(n) and sc: O(1)
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int prev1=1;
        int prev2=2;
        for(int i=3; i<=n; i++)
        {
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
