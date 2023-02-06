class Solution {
public:
    int dp[1001][1001];
    int func(int ind, int prev, vector<vector<int>>& pairs)
    {
        int n=pairs.size();
        // base case:
        // 1. when we reach end of array
        if(ind==n) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
            
        // now we can pick an ele or not pick it
        // op 1: pick
        int pick=0;
        if(prev==-1 || pairs[prev][1]<pairs[ind][0])
        {
            pick=1+func(ind+1, ind, pairs);
        }
        // op2: not pick
        int not_pick=0+func(ind+1, prev, pairs);
        return dp[ind][prev+1]=max(pick, not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // this question is similar to Q300-LIS
        // we use same kind of concept here too
        /*
        recursion:
        int func(int ind, int prev)
        {
            // base case:
            // 1. when we reach end of array
            if(ind==n) return 0;
            
            // now we can pick an ele or not pick it
            // op 1: pick
            int pick=0;
            if(prev==-1 || arr[prev][1]<arr[ind][0])
            {
                pick=1+func(ind+1, ind);
            }
            // op2: not pick
            int not_pick=0+func(ind+1, prev);
            return max(pick, not_pick);
        }
        */
        // memoization:
        // we do +1 to prev as -1 cant be as an index in array
        sort(pairs.begin(),pairs.end());
        memset(dp, -1, sizeof(dp));
        return func(0, -1, pairs);
    }
};
