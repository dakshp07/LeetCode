class Solution {
public:
    int rob(vector<int>& nums) {
        // the recursive way is to try and pick all ele and then return max
        // recursion: tc: O(2^n) and sc: O(n) which is the stack space taken by tree
        /*
        int func(int ind)
        {
        if(ind==0) return arr[ind]; // if we are at index 0 means we didnt picked 1 so we add index 0 ele to ans
        if(ind<0) return 0; // we return as we reach end
        // if we pick means we get the value of ele and then we move to i-2 as we cant take adj index
        int pick=arr[ind]+func(ind-2);
        // if we dont pick then we add 0 and move to i-1 as we can now pick adj index
        int not_pick=0+func(ind-1);
        return max(pick, not_pick);
        }
        
        // we are dealing with multiple overlapping sub problems
        // lets try memoization: tc: O(n) and sc: O(n)+O(n) for array and stack space of recusion tree
        vector<int> dp(n, -1);
        int func(int ind)
        {
        if(ind==0) return arr[ind]; // if we are at index 0 means we didnt picked 1 so we add index 0 ele to ans
        if(ind<0) return 0; // we return as we reach end
        if(dp[ind]!=-1) return dp[n]; // as we have the ans in the array
        // if we pick means we get the value of ele and then we move to i-2 as we cant take adj index
        int pick=arr[ind]+func(ind-2);
        // if we dont pick then we add 0 and move to i-1 as we can now pick adj index
        int not_pick=0+func(ind-1);
        return dp[ind]=max(pick, not_pick);
        }
        */
        // tabulation: tc: O(n) and sc: O(n) for array
        int n=nums.size();
        vector<int> dp(n, 0); // since we need max we start from 0
        // base cases
        dp[0]=nums[0];
        int neg=0;
        // start tabulation
        for(int i=1; i<n; i++)
        {
            int pick=0, not_pick=0;
            pick=nums[i]; // we always take nums[i]
            // if i-2>=0  then we take the (i-2)th step
            if(i-2>=0)
            {
                pick+=dp[i-2];
            }
            not_pick=0+dp[i-1]; // not pick
            dp[i]=max(pick, not_pick);
        }
        return dp[n-1];
    }
    // we always need the last two ele
    // space optimize: tc: O(n) and sc: O(1)
    /*
    int prev1=nums[0];
    int prev2=0;
    int pick=0, not_pick=0;
    pick=nums[i]; // we always take nums[i]
    // if i-2>=0  then we take the (i-2)th step
    if(i-2>=0)
    {
    pick+=prev2;
    }
    not_pick=0+prev1; // not pick
    prev2=prev1;
    prev1=curr;
    }
    return prev;
    */
};