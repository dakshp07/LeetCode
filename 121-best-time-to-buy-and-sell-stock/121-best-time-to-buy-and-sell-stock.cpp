class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // simple karenge
        // curr rakho, sum rakho
        int curr=INT_MAX; // curr ko min karna
        int sum=INT_MIN; // sum ko maximise karna
        for(int i=0; i<prices.size(); i++)
        {
            curr=min(prices[i], curr);
            sum=max(prices[i]-curr, sum);
        }
        return sum;
    }
};