class Solution {
public:
    int MOD=1e9+7;
    long long dp[501][501];
    long long func(int pick, int del)
    {
        // base case:
        // 1. if the no of package go negative
        if(pick<0 || del<0) return 0;
        // 2. if we have more package to pick than to deliver
        if(del<pick) return 0;
        // 3. if we have picked, and delivered all packages
        if(pick==0 && del==0) return 1;
        if(dp[pick][del]!=-1) return dp[pick][del];
        // now we have two options, either to pick or to deliver
        // we can pick any time
        // so we pick this order and move to other ones
        long long pickNow=pick*func(pick-1, del);

        // we can deliver only after we have picked (so this is handled by base case no 2)
        // we deliver one by one, so we deliver this order by del-pick
        // so we deliver this order and move to other ones
        long long delNow=(del-pick)*func(pick, del-1);

        // final ans is sum of both
        return dp[pick][del]=(pickNow+delNow)%MOD;
    }
    int countOrders(int n) {
        // so essentially we can pick first and then deliver
        // to get all possible sequences, we use recursion
        /*
        recursion:
        int func(int pick, int del)
        {
            // base case:
            // 1. if the no of package go negative
            if(pick<0 || del<0) return 0;
            // 2. if we have more package to pick than to deliver
            if(del<pick) return 0;
            // 3. if we have picked, and delivered all packages
            if(pick==0 && del==0) return 1;
            
            // now we have two options, either to pick or to deliver
            // we can pick any time
            // so we pick this order and move to other ones
            int pickNow=pick*func(pick-1, del);

            // we can deliver only after we have picked (so this is handled by base case no 2)
            // we deliver one by one, so we deliver this order by del-pick
            // so we deliver this order and move to other ones
            int delNow=(del-pick)*func(pick, del-1);

            // final ans is sum of both
            return (pickNow+delNow)%MOD;
        }
        */
        // memoization:
        memset(dp, -1, sizeof(dp));
        return func(n,n);
    }
};
