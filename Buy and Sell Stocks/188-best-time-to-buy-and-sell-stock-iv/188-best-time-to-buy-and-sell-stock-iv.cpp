class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // so this problem is very much similar to what 3 was
        // in 3 the maximum no of transaction was 2 but here the max capacity would be k
        /*
        recursion:
        int func(int ind, int buy, int cap)
        {
        if(ind==n) return 0;
        if(cap==0) return 0;
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0, cap);
        int not_take=0+func(ind+1, 1, cap);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+1, 1, cap--);
        int not_take=0+func(ind+1, 0, cap);
        int sell=max(take, not_take);
        }
        }
        
        memoization:
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        int func(int ind, int buy, int cap)
        {
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(ind==n) return 0;
        if(cap==0) return 0;
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0, cap);
        int not_take=0+func(ind+1, 1, cap);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+1, 1, cap--);
        int not_take=0+func(ind+1, 0, cap);
        int sell=max(take, not_take);
        }
        }
        */
        // tabulation:
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // base case are already done as we set dp array to 0
        // for loops
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=k; cap++)
                {
                    if(buy==0)
                    {
                        // We can buy the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][0][cap],  -prices[ind] + dp[ind+1][1][cap]);
                    }
                    if(buy==1)
                    {
                        // We can sell the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][1][cap], prices[ind] + dp[ind+1][0][cap-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};