class Solution {
public:
    int fib(int n) {
        // there are multiple ways to solve this problem
        // lets start off with recursion and will optmise it
        /*
        recursion: tc: O(2^n) and sc: O(n)
        int func(int n)
        {
        // base cases
        if(n==0) return 0;
        if(n==1) return 1;
        return func(n-1)+func(n-2);
        }
        
        memoization: tc: O(n) and sc: O(n)+O(n)
        vector<int> dp(31, -1);
        int func(int n)
        {
        if(dp[n]!=-1) return dp[n];
        // base cases
        if(n==0) return 0;
        if(n==1) return 1;
        return dp[n]=func(n-1)+func(n-2);
        }
        */
        // tabulation: tc: O(n) and sc: O(n) for array
        // vector<int> dp(31, 0);
        // base case
        // dp[0]=0;
        // dp[1]=1;
        // for loops
        // for(int i=2; i<=n; i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        // space optimized: tc: O(n) and sc: O(1)
        if(n==0) return 0;
        if(n==1) return 1;
        int prev1=0;
        int prev2=1;
        int ans=0;
        for(int i=2; i<=n; i++)
        {
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
