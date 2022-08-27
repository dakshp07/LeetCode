class Solution{
  public:
    int cutRod(int price[], int n) {
        // we will try to pick up lengths in all possible ways and then sum them up to make n
        /*
        recursion: func(4, n) means till index 4 what is the max price we can obtain in order to make a rod of en n
        int func(int ind, int n)
        {
            if(ind==0) return (n*price[0]);
            int not_take=0+func(ind-1, n);
            int tak=INT_MIN; // as we need to maximize
            int rod_len=ind+1;
            if(rod_len<=n) take=price[ind]+func(ind, n-rod_len); // as we pick up one len rod multiple time
            return max(not_take, take);
        }
        
        memoization: 
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int func(int ind, int n)
        {
            if(dp[ind][n]!=-1) return dp[ind][n];
            if(ind==0) return (n*price[0]);
            int not_take=0+func(ind-1, n);
            int tak=INT_MIN; // as we need to maximize
            int rod_len=ind+1;
            if(rod_len<=n) take=price[ind]+func(ind, n-rod_len); // as we pick up one len rod multiple time
            return dp[ind][n]=max(not_take, take);
        }
        */
        // tabulation
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        // base case
        for(int length=0; length<=n; length++)
        {
            dp[0][length]=length*price[0];
        }
        for(int ind=1; ind<n; ind++)
        {
            for(int length=0; length<=n; length++)
            {
                int not_take=0+dp[ind-1][length];
                int take=INT_MIN; // as we need to maximize
                int rod_len=ind+1;
                if(rod_len<=length) 
                {
                    take=price[ind]+dp[ind][length-rod_len]; // as we pick up one len rod multiple time
                }
                dp[ind][length]=max(not_take, take);
            }
        }
        return dp[n-1][n];
    }
};
