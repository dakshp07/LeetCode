class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // now along with the dp array we keep a cnt array as well
        // the cnt array will keep the count of the lis
        int n=nums.size();
        vector<int> dp(n), cnt(n);
        for(int i=0; i<n; i++)
        {
            dp[i]=1;
            cnt[i]=1;
            for(int prev=0; prev<i; prev++)
            {
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev]; // as we can continue that same lis so we inherit
                }
                // now if the previous dp gives same value
                else if(nums[i]>nums[prev] && 1+dp[prev]==dp[i])
                {
                    // so now they become part of same lis so increase the cnt
                    cnt[i]+=cnt[prev];
                }
            }
        }
        int lis=*max_element(dp.begin(), dp.end()); // we find the lis length
        // now in which ever ele in dp==lis we add that as cnt
        int ans=0;
        for(int i=0; i<n; i++)
        {
            // if dp[i]==lis
            if(dp[i]==lis)
            {
                // that means cnt[i] stores the cnt of subsequence that have same length as lis
                ans+=cnt[i];
            }
        }
        return ans;
    }
};