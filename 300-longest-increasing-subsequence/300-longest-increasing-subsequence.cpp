class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // we try to keep track of previous element that we choose so that we make sure that the subsequence is increasing as stated by the question
        /*
        recursion: tc: O(2^n) and sc: O(n)
        func(3, 0) means lis starting from index 3 whose previous index was 0
        prev_ind==-1 means we have not seen any prev index
        int func(int ind, int prev_index)
        {
        if(ind==n) return 0;
        // now we have two choices, to pick or not pick
        if(prev_index==-1 || arr[prev_index]<arr[ind])
        {
        // we pick
        int pick=1+func(ind+1, ind); // we move to next ele by incrementing our lis length by 1 and setting the prev_index to curr index which is picked
        }
        int not_pick=0+func(ind+1, prev_index); // the prev_index wont change if we dont pick the curr element
        len=max(pick, not_pick);
        return len;
        }
        
        memoization: tc: O(n*n) and sc: O(n*n) and O(n)
        // as ind ranges from 0 to n-1, we make dimension of n
        // but prev_index is from -1 to n-1, so we shift by one pos as -1 cant be stored in array
        // so prev_index is now from 0 to n
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int func(int ind, int prev_index)
        {
        if(dp[ind][prev_index+1]!=-1) return dp[ind][prev_index+1];
        if(ind==n) return 0;
        // now we have two choices, to pick or not pick
        if(prev_index==-1 || arr[prev_index]<arr[ind])
        {
        // we pick
        int pick=1+func(ind+1, ind); // we move to next ele by incrementing our lis length by 1 and setting the prev_index to curr index which is picked
        }
        int not_pick=0+func(ind+1, prev_index); // the prev_index wont change if we dont pick the curr element
        len=max(pick, not_pick);
        return dp[ind][prev_index+1]=len;
        }
        */
        // tabulation:
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // base case
        // when ind==n, since the dp array is already initialized from 0 we dont need to write base case
        // for(int prev_ind=0; prev_ind<=n; prev_ind++)
        // {
        //     dp[n][prev_ind]=0;
        // }
        // for loops
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int prev_index=ind-1; prev_index>=-1; prev_index--)
            {
                int pick=0, not_pick=0;
                if(prev_index==-1 || nums[ind]>nums[prev_index])
                {
                    pick=1+dp[ind+1][ind+1];
                }
                not_pick=dp[ind+1][prev_index+1];
                dp[ind][prev_index+1]=max(pick, not_pick);
            }
        }
        return dp[0][-1+1]; // as we need to shift the prev_index by +1
    }
};
