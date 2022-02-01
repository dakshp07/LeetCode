class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mib=INT_MAX;
        int pro=INT_MIN;
        int n=prices.size();
        for(int i=0; i<n; i++)
        {
            mib=min(mib, prices[i]);
            pro=max(pro, prices[i]-mib);
        }
        return pro;
    }
};