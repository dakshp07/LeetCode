class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this problem is an extension of part 2 
        // but here the only constraint is that we have to limit the buy to 2 transactions at max
        // so we do it like part 2 but here we add another check ie capacity
        /*
        recursion:
        int func(int ind, int buy, int cap)
        {
        if(ind==n) return 0;
        // what if we exceed the cap
        if(cap==0) return 0; // we get nothing
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0, cap); // since a buy sell pair is considered as one cap
        int not_take=0+func(ind+1, 1, cap);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+1, 1, cap-1); // since a buy sell pair is considered as one cap, so we reduce cap by -1
        int not_take=0+func(ind+1, 0, cap);
        int sell=max(take, not_take);
        }
        }
        
        memoization:
        // ind ranges from 0 to n-1, buy is just a bool so 0, 1 and cap is also 0, 1, 2
        vector<vector<vector<int>>> dp(n+1, vector<int>(2, vector<int>(3, -1)));
        int func(int ind, int buy, int cap)
        {
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(ind==n) return 0;
        // what if we exceed the cap
        if(cap==0) return 0; // we get nothing
        if(buy)
        {
        int take=-prices[ind]+func(ind+1, 0, cap); // since a buy sell pair is considered as one cap
        int not_take=0+func(ind+1, 1, cap);
        int buyy=max(take, not_take);
        }
        else
        {
        int take=prices[ind]+func(ind+1, 1, cap-1); // since a buy sell pair is considered as one cap, so we reduce cap by -1
        int not_take=0+func(ind+1, 0, cap);
        int sell=max(take, not_take);
        }
        }
        */
        // tabulation:
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // base case 1: ind==n then buy, cap can be anything
        // for(int buy=0; buy<=1; buy++)
        // {
        //     for(int cap=1; cap<=3; cap++)
        //     {
        //         dp[n][buy][cap]=0;
        //     }
        // }
        // base case 2: cap==2
        // for(int ind=0; ind<n; ind++)
        // {
        //     for(int buy=0; buy<=1; buy++)
        //     {
        //         dp[ind][buy][2]=0;
        //     }
        // }
        // for loops
        // since we initialized the vector by 0, we have already covered the base cases
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++)
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
        // the first index where you cant buy and also have used all transaction rules
        return dp[0][0][2];
    }
};