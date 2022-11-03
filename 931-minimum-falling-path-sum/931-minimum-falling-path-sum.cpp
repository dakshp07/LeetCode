class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // so for any ith row,col we have essentially 3 options
        // if we go greedily we might not be able to get min ans
        // so we use recursion to go through all possible ways and then choose the best
        // recursion: we start from below and go till top, so its of going below, we go up
        // tc: O(3^n) and sc: O(path length)
        /*
        int func(int row, int col)
        {
        // base case
        // out of bound
        if(col<0 || col>=n) return INT_MAX;
        // when we reach destination
        if(row==0) return arr[row][col];
        int ans=INT_MAX;
        int up=arr[row][col]+func(row-1, col);
        int diag_left=arr[row][col]+func(row-1, col-1);
        int diag_right=arr[row][col]+func(row-1, col+1);
        ans=min({ans, up, diag_left, diag_right});
        return ans;
        }
        
        memoization: tc: O(n*n) and sc: O(path length) for recursion + O(n*n) for dp array
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int func(int row, int col)
        {
        if(dp[row][col]!=-1) return dp[row][col];
        // base case
        // out of bound
        if(col<0 || col>=n) return INT_MAX;
        // when we reach destination
        if(row==0) return arr[row][col];
        int ans=INT_MAX;
        int up=arr[row][col]+func(row-1, col);
        int diag_left=arr[row][col]+func(row-1, col-1);
        int diag_right=arr[row][col]+func(row-1, col+1);
        dp[row][col]=min({ans, up, diag_left, diag_right});
        return dp[row][col];
        }
        */
        // tabulation: O(n*n) and sc: O(n*n) for dp array
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // base case
        // out of bound base case is taken care from below for loops
        // if row==0
        // when row is 0 col can be anything from 0 to n
        for(int col=0; col<n; col++)
        {
            dp[0][col]=matrix[0][col];
        }
        // for loops
        for(int row=1; row<n; row++) // start from 1
        {
            for(int col=0; col<n; col++)
            {
                int ans=INT_MAX;
                int up=matrix[row][col]+dp[row-1][col];
                int diag_left=INT_MAX;
                if(col-1>=0) diag_left=matrix[row][col]+dp[row-1][col-1];
                int diag_right=INT_MAX;
                if(col+1<n) diag_right=matrix[row][col]+dp[row-1][col+1];
                dp[row][col]=min({ans, up, diag_left, diag_right});
            }
        }
        // now since our destination is last row our ans will be the min in dp last row
        int ans=INT_MAX;
        for(int col=0; col<n; col++)
        {
            ans=min(ans, dp[n-1][col]);
        }
        return ans;
    }
};