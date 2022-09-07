class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // so you cannot buy right on the next day of selling
        // you can make unlimited trades tho
        // so this becomes similar to part 2
        /*
        recursion:
        int func(int ind, int buy)
        {
        if(ind==n) return 0;
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0);
        int not_take=0+func(ind+1, 1);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+2, 1); // instead of going to next day we move to ind+2 day and then we can buy to satisfy our condition
        int not_take=0+func(ind+1, 0);
        int sell=max(take, not_take);
        }
        }
        
        memoization:
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        int func(int ind, int buy)
        {
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(ind==n) return 0;
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0);
        int not_take=0+func(ind+1, 1);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+2, 1); // instead of going to next day we move to ind+2 day and then we can buy to satisfy our condition
        int not_take=0+func(ind+1, 0);
        int sell=max(take, not_take);
        }
        }
        */
        // tabulation:
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // base case
        // if ind==n
        // for(int buy=0; buy<=1; buy++)
        // {
        //     dp[n][buy]=0;
        // }
        // no need for base case as the dp array is already initialized from 0
        // for loops
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy==1)
                {
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
                }
                else
                {
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1], 0+dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};