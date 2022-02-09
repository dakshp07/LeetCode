class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        // debug(mp);
        int ans=0;
        for(auto x: mp)
        {
            if(k==0) // agar k==0 hoga toh ek integer ke 1 se zyaada occureneces zaruri hain
            {
                if(x.second>1)
                {
                    ans++;
                }
            }
            else
            {
                if(mp.find(x.first+k)!=mp.end())
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};