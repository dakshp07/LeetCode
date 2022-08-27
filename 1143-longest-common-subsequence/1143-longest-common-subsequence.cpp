class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // the brute force method could be to generate all subsequences of both the strings
        // and then check them to see which one is the longest common subsequence
        // tc: O(exponential)
        
        // we can use recursion and generate all the subsequences and compare them along the way
        /*
        recursion: tc: O(2^n * 2^m) where n, m are len of strings 
        func(2, 2) means the lcs of string 1 till index 2 and string2 till index 2
        if char match: now if for any ind1 and ind2 the strings char match then we shrink the search size by 1
        and add 1 in the length of this char match
        
        if char not match: we take two case move ind1-1 and keep ind2 as it is
        or move ind2-1 and keep ind1 as it is
        and take max of both moves
        
        int func(int ind1, int ind2)
        {
        if(ind1<0 || ind2<0) return 0;
        if(str1[ind1]==str2[ind2])
        {
        return 1+func(ind1-1, ind2-1);
        }
        return 0+max(func(ind1-1, ind2), func(ind1, ind2-1));
        }
        
        memoization: tc: O(n*m) and sc: O(n*m) for dp array and O(n+m) stack space
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int ind1, int ind2)
        {
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(ind1<0 || ind2<0) return 0;
        if(str1[ind1]==str2[ind2])
        {
        return dp[ind1][ind2]=1+func(ind1-1, ind2-1);
        }
        return dp[ind1][ind2]=0+max(func(ind1-1, ind2), func(ind1, ind2-1));
        }
        */
        // tabulation
        int n=text1.size(), m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case
        // now our base case is related to i<0 or j<0 which is not possible to be written in array
        // so we shift the index a lil bit
        // we started from n-1, m-1 so we now start from n, m
        // so func(i, j) will treat i, j as i-1, j-1
        // now base case is of 0, 0
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
                if(text1[i-1]==text2[j-1]) // since now we reach till n, m
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