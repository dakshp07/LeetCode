class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st;
        int mx=nums.size();
        for(int i=0; i<=mx; i++)
        {
            st.insert(i);
        }
        for(int i=0; i<nums.size(); i++)
        {
            auto it=st.find(nums[i]);
            st.erase(it);
        }
        int ans;
        for(auto it=st.begin(); it!=st.end(); it++)
        {
            ans=*it;
        }
        return ans;
    }
};