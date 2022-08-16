class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // so the sum of 1 subset should be total_sum/2 then only 2 subsets will add to become sum
        // so we just need to see if there's a subset which has a sum of total_sum/2
        // now this question becomes equal to the last question
        /*
        // recursion: tc: O(2^n) and sc: O(n)
        bool func(int ind, int target)
        {
        // base case if the target becomes 0 then we return the true as we reached our goal
        if(target==0) return true;
        // else if index is 0 then we check if arr[ind] is equal to target or not
        if(ind==0) return (arr[ind]==targt);
        bool not_take=func(i-1, target);
        bool take=false;
        // now we check if the arr[ind]<=target or not then we pick it
        // and call func for other ele
        if(arr[ind]<=target) take=func(ind-1, target-arr[ind]);
        return (take || not_take);
        }
        
        // memoization: O(n*target) and sc: O(n*target) and O(n) for recursion
        vector<vector<int>>dp(n, vector<int>(target, -1));
        bool func(int ind, int target)
        {
        if(dp[ind][target]!=-1) return dp[ind][target];
        // base case if the target becomes 0 then we return the true as we reached our goal
        if(target==0) return true;
        // else if index is 0 then we check if arr[ind] is equal to target or not
        if(ind==0) return (arr[ind]==targt);
        bool not_take=func(i-1, target);
        bool take=false;
        // now we check if the arr[ind]<=target or not then we pick it
        // and call func for other ele
        if(arr[ind]<=target) take=func(ind-1, target-arr[ind]);
        return dp[ind][target]=(take || not_take);
        }
        */
        // tabulation: O(n*target) + O(n) for sum calculation and sc: O(n*target)
        int n=nums.size();
        // lets calculate sum first
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        // if sum is odd then we cant do it /2 so we return false
        if(sum%2) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        // base case
        // we can have target 0 at all indexes, so we make all index with target 0 as true
        for(int i=0; i<n; i++)
        {
            dp[i][0]=true;
        }
        // now about index being 0 we see the target value and nums[0]
        if(nums[0]<=target) dp[0][nums[0]]=true;
        // loops for our states, ie 2 loops
        for(int i=1; i<n; i++)
        {
            for(int curr_target=1; curr_target<=target; curr_target++)
            {
                // now we pick or not pick
                bool not_take=dp[i-1][curr_target];
                bool take=false;
                if(curr_target>=nums[i]) take=dp[i-1][curr_target-nums[i]];
                dp[i][curr_target]=(take or not_take);
            }
        }
        // if we were able to find a subset with sum as target we return true
        if(dp[n-1][target]) return true;
        return false;
    }
};