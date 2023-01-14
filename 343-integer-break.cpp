class Solution {
public:
    int integerBreak(int n) {
        // as we multiple options to pick a number
        // we use recursion to explore all options
        // and then optimise the solution
        /*
        recursion: tc: O(2^n) and sc: O(n)
        ind is the number im at rn ie 1,2,.. and n is my target
        int func(int ind, int target)
        {
            // base case:
            // 1. when we reach ind at end ie 1 as 0 cant be included
            if(ind==1) return 1;
            // now i can pick any number starting from 1 and then look for the target as target-ind
            // and my multiplication product will be ind*remaing target
            if(ind<=target) int pick=ind*func(ind, target-ind);

            // if i dont pick, i will move and still look for target
            int not_pick=func(ind-1, target);
            return max(pick, not_pick);
        }

        memoization: tc: O(n) and sc: O(n) + O(n^2) for dp array
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int func(int ind, int target)
        {
            if(dp[ind][target]!=-1) return dp[ind][target];
            // base case:
            // 1. when we reach ind at end ie 1 as 0 cant be included
            if(ind==1) return 1;
            // now i can pick any number starting from 1 and then look for the target as target-ind
            // and my multiplication product will be ind*remaing target
            if(ind<=target) int pick=ind*func(ind, target-ind);

            // if i dont pick, i will move and still look for target
            int not_pick=func(ind-1, target);
            return dp[ind][target]=max(pick, not_pick);
        }
        */
        // tabulation: tc: O(n) and sc: O(n)
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        // base case:
        // 1. when we reach ind at end ie 1 as 0 cant be included
        // when ind==1 target can be anything from 0 to n
        for(int target=0; target<=n; target++) dp[1][target]=1;
        // for loops
        for(int ind=2; ind<n; ind++)
        {
            for(int target=0; target<=n; target++)
            {
                // now i can pick any number starting from 1 and then look for the target as target-ind
                // and my multiplication product will be ind*remaing target
                int pick=0;
                if(ind<=target) pick=ind*dp[ind][target-ind];

                // if i dont pick, i will move and still look for target
                int not_pick=dp[ind-1][target];
                dp[ind][target]=max(pick, not_pick);
            }
        }
        return dp[n-1][n];
    }
};
