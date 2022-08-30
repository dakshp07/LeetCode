class Solution {
public:
    int MOD = 1e9+7;
    int numDistinct(string s, string t) {
        // so we start off from the last index of both strings
        // in case if the chars at that index are equal means we move either for some diff char
        /*
        recursion: tc: O(2^n) and sc: O(m+n)
        int func(int i, int j)
        {
        if(j>0) return 1; // means ive seen all chars of my last question
        if(i>0) return 0; // if we reached our first string before verification then we put
        if(s1[i]==s1[j]) // alreasy selected peeps
        return func(i-1, j-1) + func(i-1, j)  // for i-1, we can either choose to pick that char or pick some other one
        else
        return func(i-1, j);
        }
        
        memoization: tc: O(n*m) and sc: O(n*m) as stack space of recusion and O(n+m) for dp
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int func(int i, int j)
        {
        if(dp[i][j]!=-1) return dp[i][j];
        if(j>0) return 1; // means ive seen all chars of my last question
        if(i>0) return 0; // if we reached our first string before verification then we put
        if(s1[i]==s1[j]) // alreasy selected peeps
        return func(i-1, j-1) + func(i-1, j)  // for i-1, we can either choose to pick that char or pick some other one
        else
        return dp[i][j]=func(i-1, j);
        }
        */
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case
        // for any value of j<0, i can be anything from 0 to n
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=1;
        }
        // for any value of i<0, j can be anything from 0 to m
        for(int j=1; j<=m; j++)
        {
            dp[0][j]=0;
        }
        
        // for loops
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};