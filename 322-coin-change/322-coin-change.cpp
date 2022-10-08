class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // now we have some options to choose from
        // if we go greddily then there are chances that we might get in an issue in future
        // so we explore all options and pick the best one
        // we use recursion and then optimise it further
        /*
        recursion: tc: O(2^n) and sc: O(target) 
        int func(int ind, int target)
        {
        // base case
        if(target==0) return 0;
        if(ind==0)
        {
        if(target%arr[ind]==0) return target/arr[ind];
        else return 1e9; // so we dont take it as we need minimum
        }
        // explore options
        // we can pick a specific coin and then look for target-arr[ind]
        // or we wont pick a coin and move forward
        int not_take=0+func(ind-1, target);
        // we initial take as max as we need min
        int take=INT_MAX;
        if(arr[ind]<=target) take=1+func(ind, target-arr[ind]); // as we can pick same coin again and again 
        return min(take, not_take);
        }
        
        memoization: tc: O(n) and sc: O(target)+O(n*target) for array
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int func(int ind, int target)
        {
        if(dp[ind][target]!=-1) return dp[ind][target];
        // base case
        if(target==0) return 0;
        if(ind==0)
        {
        if(target%arr[ind]==0) return target/arr[ind];
        else return 1e9; // so we dont take it as we need minimum
        }
        // explore options
        // we can pick a specific coin and then look for target-arr[ind]
        // or we wont pick a coin and move forward
        int not_take=0+func(ind-1, target);
        // we initial take as max as we need min
        int take=INT_MAX;
        if(arr[ind]<=target) take=1+func(ind, target-arr[ind]); // as we can pick same coin again and again 
        return dp[ind][target]=min(take, not_take);
        }
        */
        // tabulation: tc: O(n*target) and sc: O(n*target)
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // base case
        // when target==0, ind can be anything from 0 to n
        // we dont write it as already the entire dp array is filled with 0
        // for(int ind=0; ind<n; ind++)
        // {
        //     dp[ind][0]=0;
        // }
        // when ind==0, target can be anything from 0 to amount
        for(int target=0; target<=amount; target++)
        {
            if(target%coins[0]==0)
            {
                dp[0][target]=target/coins[0];
            }
            else dp[0][target]=1e9;
        }
        // for loops
        for(int ind=1; ind<n; ind++)
        {
            for(int target=0; target<=amount; target++)
            {
                int not_take=0+dp[ind-1][target];
                int take=INT_MAX;
                if(coins[ind]<=target) take=1+dp[ind][target-coins[ind]]; // as we can pick same coin again and again 
                dp[ind][target]=min(take, not_take);
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        return dp[n-1][amount];
    }
};