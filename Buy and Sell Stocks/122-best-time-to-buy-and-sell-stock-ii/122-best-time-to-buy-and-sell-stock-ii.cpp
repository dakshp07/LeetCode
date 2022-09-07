class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        To get the profits we have two choices.
        Choice 1 -> Buy at min price and sell at max price.
        Choice 2 -> Buy and sell whenever we can get profit.
        Choice 2 would give us max result.
        
        int profit=0;
        for(int i=0; i<prices.size()-1; i++)
        {
            if(prices[i+1]>prices[i]) // we see if the next day has higher price
            {
                // so we sell now and add the profit
                profit+=(prices[i+1]-prices[i]);
            }
        }
        return profit;
        // the above approach works, but lets see if we can solve this problem using dp
        // we can buy a stack anytime and sell it anytime, so we have multiple paths
        // lets try to explore all paths and pick the best one
        
        // recursion: tc: O(2^n) and sc: O(n)
        // the buy variable will keep a check to see if we had bought any stock previously
        // buy=0 means we cant buy, buy=1 means we can buy
        int func(int ind, int buy)
        {
        // base case is when we reach end of array as we dont have any buy sell days after that we make a profit of 0
        if(ind==n) return 0
        // if i can buy
        if(buy)
        {
        // so i can either buy on that day or not buy on that day
        // so profit will be max of buying or not buying. when we buy we are adding the price as   -price and when we sell we add that sell price to buy price in order to get profit
        profit=max(-prices[ind]+func(ind+1, 0), 0+func(ind+1, 1));
        }
        // if i cannot buy
        else
        {
        // again here we have two options either to sell or not sell
        // so profit will be max of selling or not selling. when we sell we are adding the price as +price
        profit=max(prices[ind]+func(ind+1, 1), 0+func(ind+1, 0));
        }
        return profit;
        }
        
        memoization: tc: O(n*2) and sc: O(n*2) and O(n) for recursion stake
        vector<vector<int>> dp(n, vector<int>(2, -1)); // in buy we have just 0,1 as options
        int func(int ind, int buy)
        {
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        // base case is when we reach end of array as we dont have any buy sell days after that we make a profit of 0
        if(ind==n) return 0
        // if i can buy
        if(buy)
        {
        // so i can either buy on that day or not buy on that day
        // so profit will be max of buying or not buying. when we buy we are adding the price as   -price and when we sell we add that sell price to buy price in order to get profit
        profit=max(-prices[ind]+func(ind+1, 0), 0+func(ind+1, 1));
        }
        // if i cannot buy
        else
        {
        // again here we have two options either to sell or not sell
        // so profit will be max of selling or not selling. when we sell we are adding the price as +price
        profit=max(prices[ind]+func(ind+1, 1), 0+func(ind+1, 0));
        }
        return dp[ind][buy]=profit;
        }
        */
        // tabulation:
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        long profit=0;
        // base case
        // when ind==n
        dp[n][0]=dp[n][1]=0; // as for ind=n we can have buy=0 or buy=1
        // for loops
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)
                {
                    // so i can either buy on that day or not buy on that day
                    // so profit will be max of buying or not buying. when we buy we are adding the price as   -price and when we sell we add that sell price to buy price in order to get profit
                    profit=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
                }
                // if i cannot buy
                else
                {
                    // again here we have two options either to sell or not sell
                    // so profit will be max of selling or not selling. when we sell we are adding the price as +price
                    profit=max(prices[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        // we return dp[0][1] as we start from end and reach 0 and we need to buy, sell too
        // which means that after last ele the stocks should be avaliable to buy, so buy=1
        return dp[0][1]; 
    }
};