class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // this question is preety similar to the subsequence one
        // but when we dont see a match we make that i,j in dp as 0
        // out of all the values in dp we return max as our ans
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j<=m; j++)
        {
            dp[0][j]=0;
        }
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(S1[i-1]==S2[j-1]) // since now we reach till n, m
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0; // as we need a substring so we either take it or not take it
                }
            }
        }
        // we iterate over dp array to find the maximum ans
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ans=max(dp[i][j], ans);
            }
        }
        return ans;
    }
};
