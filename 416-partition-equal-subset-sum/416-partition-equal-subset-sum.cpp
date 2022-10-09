class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // now we need to partition the array in two equal subsets which have same sum
        // so if the sum is not divisble by 2 ie sum%2==0 then we return false
        // else we need to identify one subset that can have a sum of sum/2
        // beacuse if there's one partition with a sum of sum/2 then the other remaining ele can form a partition of sum=sum/2
        // so in order to pick the partition we need to explore all options ie either pick a specific ele or not pick it
        // we use recursion and further optimise it
        /*
        recursion: tc: O(2^n) and sc: O(target)
        here target=sum/2
        bool func(int ind, int target)
        {
        // base case
        if(ind==0)
        {
        if(arr[ind]!=target) return false;
        else return true;
        }
        // explore all possibilities
        if(arr[ind]<=target) bool pick=func(ind-1, target-arr[ind]);
        bool not_pick=func(ind-1, target);
        return pick || not_pick;
        }

        memoization: tc: O(n) and sc: O(target)+O(n*target) for dp array
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        bool func(int ind, int target)
        {
        if(dp[ind][target]!=-1) return dp[ind][target];
        // base case
        if(ind==0)
        {
        if(arr[ind]!=target) return false;
        else return true;
        }
        // explore all possibilities
        if(arr[ind]<=target) bool pick=func(ind-1, target-arr[ind]);
        bool not_pick=func(ind-1, target);
        return dp[ind][target]=pick || not_pick;
        }
        */
        // tabulation: tc: O(n*target) and sc: O(n*target);
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int result=sum/2;
        vector<vector<int>> dp(n, vector<int>(result+1, 0));
        // base case
        // when ind==0, target can be anything from 0 to target
        for(int target=0; target<=result; target++)
        {
            if(nums[0]!=target) dp[0][target]=false;
            else dp[0][target]=true;
        }
        // for loops
        for(int ind=1; ind<n; ind++)
        {
            for(int target=0; target<=result; target++)
            {
                // explore all possibilities
                bool pick=false;
                bool not_pick=false;
                if(nums[ind]<=target) pick=dp[ind-1][target-nums[ind]];
                not_pick=dp[ind-1][target];
                dp[ind][target]=pick || not_pick;
            }
        }
        return dp[n-1][result];
    }
};