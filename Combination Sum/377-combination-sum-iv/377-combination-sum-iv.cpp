class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // so we use recursion to identify the no of combinations
        // the recursion will take an ele if its less than target value
        // and then call recursion to look for func(arr[i]-target)
        // which creates overlapping subproblems, so we can optimize it with memo and tabu
        /*
        reucrsion: tc: O(expo) and sc: O(target)
        int func(int target)
        {
        // base case 
        if(target==0) return 1;
        int ways=0;
        for(int i=0; i<nums.size(); i++)
        {
        if(nums[i]<=target) ways+=func(target-nums[i]);
        }
        return ways;
        }
        
        memoization: tc: O(target) and sc: O(target)+O(target) for dp array
        vector<int> dp(target+1, -1);
        int func( int target)
        {
        if(dp[target]!=-1) return dp[target];
        // base case 
        if(target==0) return 1;
        int ways=0;
        for(int i=0; i<nums.size(); i++)
        {
        if(nums[i]<=target) ways+=func(target-nums[i]);
        }
        return dp[target]=ways;
        }
        */
        // tabulation: tc: O(target) and sc: O(target)
        vector<int> dp(target+1, 0);
        // base case
        dp[0]=1;
        for(int curr_target=1; curr_target<=target; curr_target++)
        {
            long long ways=0;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]<=curr_target) ways+=dp[curr_target-nums[i]];
            }
            dp[curr_target]=ways;
        }
        return dp[target];
    }
};