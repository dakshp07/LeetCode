class Solution {
public:
    int minDistance(string word1, string word2) {
        // since we can perform 3 operations ie insert, delete, replace
        // so we will try all this 3 ways and return the minimum possible value as ans
        /*
        recursion: func(n-1, m-1) signifies the minimum number of operations required to convert s1 from [0...n-1] to s2[0....m-1]. tc: O(exp) and sc: O(n+m)
        int func(int i, int j)
        {
        // if the strings char match with each other then we just need to move ahead
        if(s1[i]==s2[j]) return 0+func(i-1, j-1); // 0 as we didnt peform any step
        // now what if they dont match, then we can do any of the 3 operations
        // we do an insertion of char and since now they matach we move j pointer
        int ins=1+func(i, j-1); // as the new char got added at end of string
        // next either we can do delete, so we just move i pointer
        int del=func(i-1, j); // as we deleted but still we are looking for j
        // now we can just replace
        int rep=func(i-1, j-1); // as we replace and now they match so we move
        // for base case we have 2 cases, if str1 is exhausted or if str2 is exhausted
        // when str1 is exhausted, in that case the minimum number of operations will be the char remaining in str2
        return min(ins, min(del, rep));
        if(i<0) return j+1;
        // when str2 is exhausted, in that case the minimum number of operations will be the char remaining in str1
        if(j<0) return i+1;
        }
        
        memoization: tc: O(n*m) and sc: O(n*m) + O(n+m)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int i, int j)
        {
        if(dp[i][j]!=-1) return dp[i][j];
        // if the strings char match with each other then we just need to move ahead
        if(s1[i]==s2[j]) return 0+func(i-1, j-1); // 0 as we didnt peform any step
        // now what if they dont match, then we can do any of the 3 operations
        // we do an insertion of char and since now they matach we move j pointer
        int ins=func(i, j-1); // as the new char got added at end of string
        // next either we can do delete, so we just move i pointer
        int del=func(i-1, j); // as we deleted but still we are looking for j
        // now we can just replace
        int rep=func(i-1, j-1); // as we replace and now they match so we move
        // for base case we have 2 cases, if str1 is exhausted or if str2 is exhausted
        // when str1 is exhausted, in that case the minimum number of operations will be the char remaining in str2
        return dp[i][j]=1+min(ins, min(del, rep));
        if(i<0) return j+1;
        // when str2 is exhausted, in that case the minimum number of operations will be the char remaining in str1
        if(j<0) return i+1;
        }
        */
        // tabulation:
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case
        // when i=0
        for(int j=0; j<=m; j++)
        {
            dp[0][j]=j;
        }
        // when j=0
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=i;
        }
        // for loops
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int ins=dp[i][j-1]; // as the new char got added at end of string
                    // next either we can do delete, so we just move i pointer
                    int del=dp[i-1][j]; // as we deleted but still we are looking for j
                    // now we can just replace
                    int rep=dp[i-1][j-1]; // as we replace and now they match so we move
                    dp[i][j]=1+min(ins, min(del, rep));
                }
            }
        }
        return dp[n][m];
    }
};