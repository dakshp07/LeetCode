class Solution {
public:
    int MOD=1e9+7;
    // int dp[n][absent][late]
    int dp[100001][4][4];
    int func(int n, int absent, int late)
    {
        // base case:
        // 1. if student is abs for more than 2 days
        if(absent>=2) return 0;
        // 2. if student is late for 3 or more days
        if(late>=3) return 0;
        // 3. if we have used all n
        if(n==0) return 1;

        if(dp[n][absent][late]!=-1) return dp[n][absent][late];

        // now we have 3 options
        // 1. if student is present, we move to next day
        int op1=func(n-1, absent, 0); // we make late as 0, since we need to check if student is consecutively late
        //2. if student is absent, we move to next day but with 1 absent
        int op2=func(n-1, absent+1, 0); // we make late as 0, since we need to check if student is consecutively late
        //3. if student is absent, we move to next day but with 1 late
        int op3=func(n-1, absent, late+1);

        // now we return ans
        return dp[n][absent][late]=((op1+op2)%MOD+op3)%MOD;
    }
    int checkRecord(int n) {
        // so we need to get all possible ways and sum them
        // we use recursion to get all possible answers
        /*
        recursion:
        int func(int n, int absent, int late)
        {
            // base case:
            // 1. if student is abs for more than 2 days
            if(absent>=2) return 0;
            // 2. if student is late for 3 or more days
            if(late>=3) return 0;
            // 3. if we have used all n
            if(n==0) return 1;

            // now we have 3 options
            // 1. if student is present, we move to next day
            int op1=func(n-1, absent, 0); // we make late as 0, since we need to check if student is consecutively late
            //2. if student is absent, we move to next day but with 1 absent
            int op2=func(n-1, absent+1, 0); // we make late as 0, since we need to check if student is consecutively late
            //3. if student is absent, we move to next day but with 1 late
            int op3=func(n-1, absent, late+1);

            // now we return ans
            return (op1+op2+op3)%MOD;
        }
        */
        // memoization:
        memset(dp, -1, sizeof(dp));
        return func(n, 0, 0); // we start off with 0 absent, 0 lates
    }
};
