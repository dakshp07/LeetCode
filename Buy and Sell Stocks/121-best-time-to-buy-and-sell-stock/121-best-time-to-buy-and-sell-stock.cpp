class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // maximize karna hain profit
        // matlab buying price should be as small as possible
        // but the difference b/w buying and selling should be maximum
        int buy=INT_MAX;
        int profit=INT_MIN;
        for(int i=0; i<prices.size(); i++)
        {
            // minimize buy
            buy=min(buy, prices[i]);
            // maximize the profit
            profit=max(profit, prices[i]-buy);
        }
        return profit;
    }
};