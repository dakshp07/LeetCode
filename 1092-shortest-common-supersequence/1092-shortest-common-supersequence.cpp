class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // our main idea here is to make sure that we get the common chars from the both strings just once
        // because only in such cases we will get the samllest common supersequence
        // so the length of the supersequence will be: len1+len2-len(lcs)
        
        // now we have the length of the supersequence, we need to print it
        // in order to print it we follow same process as we did in LCS
        // but if we see a atch char we add that same char just once in order to make sure that we the shortest supersequence
        
        // lets find the lcs first
        int n=str1.size(), m=str2.size();
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
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0+max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // now lets get the supersequence
        string ans="";
        int i=n;
        int j=m;
        // we will pick th chars similarly as we did in lcs
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                // we pick that char once and move
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
        // now if we have any more chars left in str1 or str2 we take them in
        while(i>0)
        {
            ans+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};