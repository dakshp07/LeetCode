class Solution {
public:
    int uniquePaths(int m, int n) {
        // we use recursion to try all paths possible
        // and then we use memoization to reduce tc for overlapping sub problems
        // and tabulation to reduce tc even more
        /*
        recursion: tc: O(2^n) and sc: O(path length) as we will travel our entire path
        int func(int row, int col)
        {
        // we start from (m-1,n-1)
        // base case: if we reach (0,0) we return 1
        if(row==0 && col==0) return 1;
        // out of bounds cases
        if(row<0 || col<0) return 0; 
        // we move up and left as we coming from (m-1,n-1)
        int up=func(row-1, col);
        int left=func(row, col-1);
        return up+left;
        }
        
        memoization: tc: O(2^n) and sc: O(path length) + O(n*m);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int row, int col)
        {
        if(dp[row][col]!=-1) return dp[row][col];
        // we start from (m-1,n-1)
        // base case: if we reach (0,0) we return 1
        if(row==0 && col==0) return 1;
        // out of bounds cases
        if(row<0 || col<0) return 0; 
        // we move up and left as we coming from (m-1,n-1)
        int up=func(row-1, col);
        int left=func(row, col-1);
        return dp[row][col]=up+left;
        }
        */
        // tabulation: tc: O(n*m) and sc: O(n*m)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // base case
        dp[0][0]=1;
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(row==0 && col==0) dp[row][col]=1;
                else
                {
                    // handling out of bound cases ie base case of row<0 || col<0
                    int up=0, left=0;
                    if(row>0) up=dp[row-1][col];
                    if(col>0) left=dp[row][col-1];
                    dp[row][col]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};