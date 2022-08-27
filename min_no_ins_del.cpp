int canYouMake(string &str, string &ptr)
{
    // so the best, optimal way to insert or delete char is to not touch the char which are common in both the strings
    // so we find the lcs among both strings
    // deletions: the char which are in string1 - len of lcs, n-len(lcs)
    // insertions: the char which are in string2 should be added in string 1. so, m-len(lcs)
    int n=str.size(), m=ptr.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // base case
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
            if(str[i-1]==ptr[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=0+max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int del=n-dp[n][m];
    int ins=m-dp[n][m];
    return del+ins;
}
