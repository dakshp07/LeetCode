const int mod=(int)(2e9);
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // everything is same as unqiue paths i
        // we just got a new condition
        /*
        recursion: tc: O(2^m*n) and sc: O(path length)
        int func(int row, int col)
        {
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        // if the row and col are valid the arr ele at that index is 1 we dont go
        if(row>=0 && col>=0 && arr[row][col]==1) return 0;
        int up=func(row-1, col);
        int left=func(row, col-1);
        return up+left;
        }
        
        memoization: tc: O(m*n) and sc: O(path length) + O(n*m)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int row, int col, vector<int> &dp)
        {
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        // if the row and col are valid the arr ele at that index is 1 we dont go
        if(row>=0 && col>=0 && arr[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int up=func(row-1, col, dp);
        int left=func(row, col-1, dp);
        return dp[row][col]=up+left;
        }
        */
        // tabulation: tc: O(m*n) and sc: O(n*m)
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // base cases
        dp[0][0]=1;
        // iterate
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                // new addition for cases when arr[i][j]==1
                else
                {
                    int up=0, left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=(up+left)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};