class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // as usual we start off from wiritng recursion and check all paths
        // we pick the minimum among all the paths
        /*
        recursion: tc: O(2^n) and sc: O(path length)
        int func(int row, int col)
        {
        if(row==0 && col==0) return arr[0][0]; // as we reach our destination
        if(row<0 || j<0) return 1e9; // as we dont include this in our minimum path, so we make it maximum
        int up=func(row-1, col)+arr[row][col]; // as we take that in our path
        int left=func(row, col-1)+arr[row][col];
        return min(up, left);
        }
        
        memoization: tc: O(n*m) and sc: O(path length)+O(n*m) for array
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int row, int col)
        {
        if(row==0 && col==0) return arr[0][0]; // as we reach our destination
        if(row<0 || j<0) return 1e9; // as we dont include this in our minimum path, so we make it maximum
        if(dp[row][col]!=-1) return dp[row][col];
        int up=func(row-1, col)+arr[row][col]; // as we take that in our path
        int left=func(row, col-1)+arr[row][col];
        return dp[row][col]=min(up, left);
        }
        */
        // tabulaion: tc: O(n*m) and sc: O(n*m)
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0]=grid[0][0]; // base case
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else
                {
                    int up=grid[i][j]; // add that cell value
                    if(i>0)
                    {
                        up+=dp[i-1][j]; // if we can go up we add that cell value too
                    }
                    else up+=1e9; // if we cant go up we make that path unreachable ie max
                    int left=grid[i][j]; // add that cell value
                    if(j>0)
                    {
                        left+=dp[i][j-1]; // if we can go left we add that cell value too
                    }
                    else left+=1e9; // if we cant go left we make that path unreachable ie max
                    dp[i][j]=min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};