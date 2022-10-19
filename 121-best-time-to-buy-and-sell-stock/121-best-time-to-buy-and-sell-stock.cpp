class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // so we need to maximize the profit ie profit should be high
        // for profit to maximize the buy should be low
        int buy=INT_MAX;
        int profit=INT_MIN;
        for(int i=0; i<prices.size(); i++)
        {
            buy=min(prices[i], buy);
            profit=max(profit, prices[i]-buy);
        }
        return profit;
    }
};