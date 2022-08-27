class Solution {
public:
    int minInsertions(string s) {
        // any string can be made a palindrome by adding the string s reverse
        // s+reverse(s), no of operations=len(s)
        // our main motive here will be to make sure that we keep the longest palindromic substring intact and make operations on other char
        // so the part which is not an palindromic substring will be the ans because we can paste that part on any of the other side
        // so our ans will be n-lps
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case
        for(int j=0; j<=m; j++)
        {
            dp[0][j]=0;
        }
        for(int i=0; i<=n; i++)
        {
            dp[0][i]=0;
        }
        // for loops
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0+max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lps=dp[n][m];
        return n-lps;
    }
};