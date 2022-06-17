class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // multiple ways to do:
        // 1) use set:
        // unordered_set<int> st;
        // int mx=nums.size();
        // for(int i=0; i<=mx; i++)
        // {
        //     st.insert(i);
        // }
        // for(int i=0; i<nums.size(); i++)
        // {
        //     auto it=st.find(nums[i]);
        //     st.erase(it);
        // }
        // int ans;
        // for(auto it=st.begin(); it!=st.end(); it++)
        // {
        //     ans=*it;
        // }
        // return ans;
        
        // 2) find sum of n natural nums, and then subtract it from the sum of ele in arr
        int n=nums.size();
        int tsum=(n*(n+1))/2;
        int sum=accumulate(nums.begin(), nums.end(), 0);
        return tsum-sum;
    }
};