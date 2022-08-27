string lcs(vector<vector<int>> &dp, string ans, int n, int m, string text1, string text2)
    {
        int len=dp[n][m];
        for(int i=0; i<len; i++)
        {
            ans='$'; // dummy char, so that we can access index of string
        }
        int ind=len-1;
        int i=n, j=m;
        // we backtrack from last ele of dp matrix and see where that val is coming from
        while(i>0 && j>0)
        {
            // if the char at those index are equal
            if(text1[i-1]==text2[j-1])
            {
                // then we add char to ans and move forward
                ans[ind]=text1[i-1];
                ind--;
                i--, j--;
            }
            // if char are not equal so we might have come at that ele from 2 pos ie i-1, j or i, j-1
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        cout<<ans;
    }
