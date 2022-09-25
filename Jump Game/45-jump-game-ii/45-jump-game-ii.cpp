class Solution {
public:
    int jump(vector<int>& nums) {
        // so we need to explore all the possibilities using recursion
        // and then we use further optimization to reduce calls
        /*
        recursion: tc: O(n*n) and sc: O(the no of steps)
        int func(int ind)
        {
        // -1 bc in loop 1 + func(), if func() returns INT_MAX, 1+INT_MAX will result stack overflow
        int min_steps=INT_MAX-1;
        // base case
        if(ind==n-1) return 0;
        // for loops, we can take from 1 to nums[ind] steps at max
        for(int j=1; j<=nums[ind]; j++)
        {
        if(ind+j<nums.size())
        {
        // at i take 1 step of length j, so we reach ind+j
        min_steps=min(1+func(ind+j, min_steps));
        }
        }
        return min_steps;
        }
        
        memoization: tc: O(n) and sc: O(the no of steps) and O(n)
        vector<int> dp(n, 1001); // we dont take -1 as we need min in the return
        int func(int ind)
        {
        if(dp[ind]!=1001) return dp[ind]
        // -1 bc in loop 1 + func(), if func() returns INT_MAX, 1+INT_MAX will result stack overflow
        int min_steps=INT_MAX-1;
        // base case
        if(ind==n-1) return 0;
        // for loops, we can take from 1 to nums[ind] steps at max
        for(int j=1; j<=nums[ind]; j++)
        {
        if(ind+j<nums.size())
        {
        // at i take 1 step of length j, so we reach ind+j
        min_steps=min(1+func(ind+j, min_steps));
        }
        }
        return dp[ind]=min_steps;
        }
        */
        
        // tabulation: O(n) and sc: O(n)
        int n=nums.size();
        vector<int> dp(n, 0);
        // base case: no need to write as the entire dp array as 0
        // dp[n-1]=0;
        // for loops: starts from n-2 as we have a base case for n-1
        for(int ind=n-2; ind>=0; ind--)
        {
            int min_steps=INT_MAX-1;
            for(int j=1; j<=nums[ind]; j++)
            {
                // to make sure that ind+j never goes out
                if(ind+j<nums.size())
                {
                    // at i take 1 step of length j, so we reach ind+j
                    min_steps=min(1+dp[ind+j], min_steps);
                }
            }
            dp[ind]=min_steps;
        }
        return dp[0];
    }
};