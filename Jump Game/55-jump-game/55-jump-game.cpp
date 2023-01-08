// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        // so at every index i we have nums[i] options
        // greedily will work here but we still try recursion
        // and probably then optimise it
        /*
        recursion: starts from 0th index till n-1th index
        bool func(int ind)
        {
            int n=nums.size();
            // base case:
            // 1. if we reach the destination ie n-1th index
            if(ind==n-1) return true;
            // 2. if we move past destination
            if(ind>n-1) return false;
            // now at any index ind we can take 1 to nums[ind] steps
            bool ans=false;
            for(int steps=1; steps<=nums[ind]; steps++)
            {
                // so we check all possibility hence we use an || operator
                ans=ans || func(ind+steps);
            }
            return ans;
        }

        memoization:
        vector<int> dp(n, -1);
        bool func(int ind)
        {
            int n=nums.size();
            if(dp[ind]!=-1) return dp[ind]
            int n=nums.size();
            // base case:
            // 1. if we reach the destination ie n-1th index
            if(ind==n-1) return true;
            // 2. if we move past destination
            if(ind>n-1) return false;
            // now at any index ind we can take 1 to nums[ind] steps
            bool ans=false;
            for(int steps=1; steps<=nums[ind]; steps++)
            {
                // so we check all possibility hence we use an || operator
                ans=ans || func(ind+steps);
            }
            return ans;
        }
        */
        // tabulation:
        // int n=nums.size();
        // vector<bool> dp(n, false);
        // base case:
        // 1. if we reach the destination ie n-1th index
        // dp[n-1]=true;
        // 2. if we move past destination (it can be handled in for loops)
        // if(ind>n-1) return false;
//         for(int ind=n-2; ind>=0; ind--)
//         {
//             // we start from 1 as we have shifted the index for base case #2
//             for(int steps=0; steps<=nums[ind]; steps++)
//             {
//                 if(ind+steps<n && dp[ind+steps]==true)
//                 {
//                     dp[ind]=true;
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// the above was a recursion, memoization and tabulation way to solve the problem
// but we solve it more efficiently using greed method

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // we will calculate the max index that we can reach from any index i
        // if at the end we were able to reach the size of array -1 then we are good to go
        int reachable=0;
        for(int i=0; i<nums.size(); i++)
        {
            // now every arr[i] tell us the max no of steps that we can take
            // we start from index 0, so max step we can take from here is 0+arr[0]
            
            if(reachable<i) return false; // because we cant even reach next index
            // we just pick max of the value
            reachable=max(reachable, i+nums[i]);
        }
        // if our reachable==last index we return true else we return false
        return true;
    }
};
