class Solution {
public:
    int rob(vector<int>& nums) {
        // since there are multiple options fror the robber to pick
        // one would think that greedy will help but greedy might affect the future decision
        // and give wrong ans
        // so we use recursion and then optimise it
        /*
        recursion: tc: O(2^n) and sc: O(n)
        int func(int ind)
        {
        // base case
        if(ind==0) return arr[ind];
        // now we have 2 options, we can either pick ind index or not pick
        // if we pick we move to ind+2 or else we move to ind+1
        int pick=arr[ind]+func(ind-2);
        int not_pick=0+func(ind-1);
        sum=max(pick, not_pick);
        return sum;
        }
        
        memoization: tc: O(n) and sc: O(n)+O(n)
        vector<int> dp(n, -1);
        int func(int ind)
        {
        if(dp[ind]!=-1) return dp[ind];
        // base case
        if(ind==0) return arr[ind];
        // now we have 2 options, we can either pick ind index or not pick
        // if we pick we move to ind+2 or else we move to ind+1
        int pick=arr[ind]+func(ind-2);
        int not_pick=0+func(ind-1);
        sum=max(pick, not_pick);
        return dp[ind]=sum;
        }
        */
        // tabulation: tc: O(n) and sc: O(n)
        int n=nums.size();
        vector<int> dp(n+1, 0);
        // base case
        dp[0]=nums[0];
        // for loops
        for(int ind=1; ind<n; ind++)
        {
            int pick=0, not_pick=0;
            pick=nums[ind];
            if(ind-2>=0) pick+=dp[ind-2];
            not_pick=0+dp[ind-1];
            dp[ind]=max(pick, not_pick);
        }
        return dp[n-1];
    }
};