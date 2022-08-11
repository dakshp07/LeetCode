class Solution {
public:
    int func(vector<int>& nums, vector<int> &dp)
    {
        int n=nums.size();
        dp[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            int pick=0, not_pick=0;
            pick=nums[i];
            if(i-2>=0)
            {
                pick+=dp[i-2];
            }
            not_pick=0+dp[i-1];
            dp[i]=max(pick, not_pick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        // we will have the same logic as of the house robber 1
        // we just check two cases
        // 1. When we include first ele in ans and exclude the last one
        // 2. When we include last ele in ans and exclude the first one
        // everything else is same so we go and do the tabulation
        int n=nums.size();
        if(n==1) return nums[0]; // base case when only one ele is there
        vector<int> dp(n, 0);
        vector<int> no_first, no_last; // 2 vector to store the not first array, and not last array
        // Case 1: we take first ele
        for(int i=0; i<n-1; i++)
        {
            no_last.push_back(nums[i]);
        }
        // Case 2: we take last ele
        for(int i=1; i<n; i++)
        {
            no_first.push_back(nums[i]);
        }
        // call our dp function for both vector
        int first=func(no_last, dp);
        int last=func(no_first, dp);
        // return max of both
        return max(first, last);
    }
};