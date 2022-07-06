class Solution {
public:
    int fib(int n) {
        // recurive way:
        // if(n==0) return 0;
        // if(n==1) return 1;
        // return fib(n-1)+fib(n-2);
        
        // dp way: much efficient since you reduce the tree by saving ans
        vector<int> dp(31);
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<31; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};