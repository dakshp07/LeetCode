class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // so we need to find a subsequence which is longest and is also a palindrome
        // so what we observe in palinrome is that its char at start match with the char at end
        // so essentially we need to find the LCS b/w the original string and its reverse
        // eg: s="bbbab" rev_s="babbb", this both lcs: "bbbb" which is alo the lps
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
            dp[i][0]=0;
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
        return dp[n][m];
    }
};