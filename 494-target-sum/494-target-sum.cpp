class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // lets say we have two subsets x, y with x subset containing all elements which are added
        // and negative numbers all are added to y
        /*
        // so essentially we need to identify x, y such that x-y==target
        // which again is similar to count no of ways or partiton sum
        
        // recursion:
        // recursion: tc: O(2^n) and sc: O(n)
        int func(int ind, int target)
        {
        if(target==0) return 1;
        if(ind==0)
        {
        if(target==0 && arr[0]==0)
        return 2;
        if(target==0 || target == arr[0])
        return 1;
        return 0;
        }
        int not_pick=func(ind-1, target);
        int pick=0;
        if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
        return pick+not_pick;
        }
    
        // memoization: tc: O(n*sum) sc: O(n*sum) for array and sc: O(n) for stack space
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int func(int ind, int target)
        {
        if(dp[ind][target]!=-1) return dp[ind][target]
        if(target==0) return 1;
        if(ind==0)
        {
        if(target==0 && arr[0]==0)
        return 2;
        if(target==0 || target == arr[0])
        return 1;
        return 0;
        }
        int not_pick=func(ind-1, target);
        int pick=0;
        if(arr[ind]<=target) pick=func(ind-1, target-arr[ind]);
        return  dp[ind][target]=pick+not_pick;
        */
        // tabulation:
        int n= nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum-target < 0 or (sum-target)%2) return 0;
        int tar = (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(tar+1, 0));
        if(nums[0]==0) dp[0][0] = 2;
        else dp[0][0]=1;
        if(nums[0]!=0 and tar>=nums[0]) dp[0][nums[0]] =1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int np = dp[i-1][j];
                int p = 0;
                if(j>=nums[i]) p = dp[i-1][j-nums[i]];
                dp[i][j] = p+np;
            }
        }
        return dp[n-1][tar];
    }
};