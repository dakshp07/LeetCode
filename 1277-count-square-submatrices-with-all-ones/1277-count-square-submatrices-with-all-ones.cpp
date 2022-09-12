class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // for problems related to squares recursion is not very intuitive
        // so we straightaway jump to tabulation which is more intuitive
        // we make an dp matrix of same size 
        // dp[i][j]=means how many squares end at (i,j) ie (i,j) are the bottom right for squares
        // for first row and first col the dp[i][j] will be same as matrix value of first row and col as they are the bottom right for themselves
        // for every dp[i][j] we take minimum of the one top ele, one left ele and one digonal top ele and +1 to it as that (i,j) can form one from themself
        // dp[i][j]=min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1 this is valid only if the matrix[i][j]=1
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // base case
        // for first row, col the values will be same as values of matrix in first row, col
        for(int i=0; i<n; i++)
        {
            dp[i][0]=matrix[i][0];
        }
        for(int i=0; i<m; i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                // we apply formula only if the matrix[i][j]==1
                if(matrix[i][j]==1)
                {
                    dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                }
            }
        }
        // the ans is sum of all values in dp
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};