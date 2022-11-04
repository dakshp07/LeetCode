class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // in the part i of the question we had 3 choices
        // in this one we dont have a choice rather we have a restriction
        // we cannot visit the same col with adj row
        // but we can go on any other col
        // so again we explore possibilities
        /*
        recursion: same as part i we start from last row and move to top
        tc: O(n^n-1) as for all n we have n-1 options and sc: O(path length)
        int func(int row, int col)
        {
        // base case:
        // out of bounds
        if(col<0 || col>=n) return INT_MAX;
        // if we reach our destination
        if(row==0) return arr[row][col];
        // explore possibilties:
        // so we can visit any col in the above row but not the same col as previous one
        int ans=INT_MAX;
        for(int new_col=0; new_col<n; new_col++)
        {
        // if we get a col same as previous one, we skip it
        if(new_col==col) continue;
        // else we take this col and keeping exploring and pick our min ans
        else
        {
        ans=min(ans, grid[row][col]+func(row-1, new_col));
        }
        }
        return ans;
        }
        
        memoization: tc: O(n*n-1) and sc: O(path length) for recursion + O(n*n) for array
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int func(int row, int col)
        {
        if(dp[row][col]!=-1) return dp[row][col];
        // base case:
        // out of bounds
        if(col<0 || col>=n) return INT_MAX;
        // if we reach our destination
        if(row==0) return arr[row][col];
        // explore possibilties:
        // so we can visit any col in the above row but not the same col as previous one
        int ans=INT_MAX;
        for(int new_col=0; new_col<n; new_col++)
        {
        // if we get a col same as previous one, we skip it
        if(new_col==col) continue;
        // else we take this col and keeping exploring and pick our min ans
        else
        {
        ans=min(ans, grid[row][col]+func(row-1, new_col));
        }
        }
        return dp[row][col]=ans;
        }
        */
        // tabulation: tc: O(n*n-1) and sc: O(n*n) for array
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // as we need min in ans
        // base case
        // when row==0, col can be anything from 0 to n-1
        for(int col=0; col<n; col++)
        {
            dp[0][col]=grid[0][col];
        }
        // out of bound base case is handled in the for loops
        // for loops
        for(int row=1; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                int ans=INT_MAX;
                for(int new_col=0; new_col<n; new_col++)
                {
                    // if we get a col same as previous one, we skip it
                    if(new_col==col) continue;
                    // else we take this col and keeping exploring and pick our min ans
                    else
                    {
                        ans=min(ans, grid[row][col]+dp[row-1][new_col]);
                    }
                }
                dp[row][col]=ans;
            }
        }
        // since our goal is to reach last row, our dp array will have ans stored in last row
        // we need to return min of them all
        int ans=INT_MAX;
        for(int col=0; col<n; col++)
        {
            ans=min(ans, dp[n-1][col]);
        }
        return ans;
    }
};