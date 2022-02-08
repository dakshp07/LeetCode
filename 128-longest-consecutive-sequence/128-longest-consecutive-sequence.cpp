class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(int i=0; i<n; i++)
        {
        st.insert(nums[i]);
        }
        vector<int> v;
        for(auto it=st.begin(); it!=st.end(); it++)
        {
            v.push_back(*it);
        }
        int ans=0, count=0;
        for(int i=0; i<v.size(); i++)
        {
            if(i>0 && v[i-1]+1==v[i])
            {
                count++;
            }
            else
            {
                count=1;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};