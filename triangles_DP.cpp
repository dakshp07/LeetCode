int minimumPathSum(vector<vector<int>>& triangle, int n){
    // we can move either diagnoally on right or we can move straight down
    // starting point is fixed but variable ending point
    // we will try all the points in the last row using recursion
    /*
    // recursion: O(2^n) and sc: O(n)
    int func(int row, int col)
    {
    // we dont have a fixed ending point so unlike last time when we started from n-1, m-1 and reached 0, 0 we cant do here as the ending point is variable
    // so we will start from top as its fixed
    
    // base case will be when we reach the last row as all the points are on that row
    if(row==n-1) return arr[row-1][col];
    // no we have two steps go down (row+1, col) or diagnoal (row+1, col+1)
    int down=arr[row][col]+func(row+1, col);
    int diag=arr[row][col]+func(row+1, col+1);
    // return min
    return min(down, diag);
    }
    
    // memoization: tc: O(n*m) sc: O(n) for recursion and O(n*m) for array
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int func(int row, int col)
    {
    if(dp[row][col]!=-1) return dp[row][col];
    // we dont have a fixed ending point so unlike last time when we started from n-1, m-1 and reached 0, 0 we cant do here as the ending point is variable
    // so we will start from top as its fixed
    
    // base case will be when we reach the last row as all the points are on that row
    if(row==n-1) return arr[row-1][col];
    // no we have two steps go down (row+1, col) or diagnoal (row+1, col+1)
    int down=arr[row][col]+func(row+1, col);
    int diag=arr[row][col]+func(row+1, col+1);
    // return min
    return dp[row][col]=min(down, diag);
    }
    */
    // tabulation: tc: <=O(n*m) and sc: O(n*m) for array
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // the base case is when we reach the last row, so lets run a for loop for all col
    for(int j=0; j<n; j++)
    {
        dp[n-1][j]=triangle[n-1][j]; // covering all cols of last row
    }
    // we start from n-2 to fill our dp table as we already covered our (n-1)th row
    // also for any (i)th row we have (i+1) cols, so we make for loop accordingly
    for(int i=n-2; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int down=triangle[i][j]+dp[i+1][j];
            int diag=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down, diag);
        }
    }
    return dp[0][0]; // as we went from last to (0, 0)
}
