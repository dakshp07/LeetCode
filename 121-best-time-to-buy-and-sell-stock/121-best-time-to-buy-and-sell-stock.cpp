class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // so we can do multiple ways to solve this problem
        // one of the ways brute force is to check all the permutations and combinations
        // and check in which combination we are getting the maximum profit
        // but that will require two loops. tc: O(n^2)
        // instead we can do one thing: we need to maximize the profit which means
        // we need to minimize the buy price
        int buy=INT_MAX;
        int max_profit=INT_MIN;
        for(int i=0; i<prices.size(); i++)
        {
            buy=min(buy, prices[i]);
            max_profit=max(max_profit, prices[i]-buy);
        }
        return max_profit;
    }
};