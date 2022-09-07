class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // now the condition is that we have to pay a transaction fee for every sell
        // again we can make unlimited buy sells but now fee should be paid
        // similar to part 2 but just add the fee logic
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
        int take=prices[ind]-fee+func(ind+1, 1); // we pay the fee once we sell
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
        int take=prices[ind]-fee+func(ind+1, 1); // we pay the fee once we sell
        int not_take=0+func(ind+1, 0);
        int sell=max(take, not_take);
        }
        }
        */
        // tabulation:
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // base case
        // when ind==n, no need to write as we have already intialized the array as 0
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
                    dp[ind][buy]=max(prices[ind]-fee+dp[ind+1][1], 0+dp[ind+1][0]);
                }
            }
        }
        // as start from n-1, so end ans is in 0th index
        // and as we have sold the sold ie we completed transaction we need to make it avaliable for buy, so that is buy==1
        // therefore our ans is in dp[0][1]
        return dp[0][1];
    }
};