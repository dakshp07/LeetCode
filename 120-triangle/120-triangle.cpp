class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // so we have two options, greedy might not give the best solution
        // so we try both the options and choose minimum one
        // we use recursion for this, and optimise it further
        /*
        recursion: starts from top and we reach till bottom
        tc: O(2^n) and sc: O(no of rows)
        int func(int row, int col)
        {
            // base case:
            // 1. when we have reached the bottom row
            if(row==n-1) return arr[row][col];
            // now we go for both options
            int op_1=arr[row][col]+func(row+1, col);
            int op_2=arr[row][col]+func(row+1, col+1);
            return min(op_1, op_2);
        }

        memoization: O(2^n) and sc: O(no of rows) + O(n*m) for dp array
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int row, int col)
        {
            if(dp[row][col]!=-1) return dp[row][col];
            // base case:
            // 1. when we have reached the bottom row
            if(row==n-1) return arr[row][col];
            // now we go for both options
            int op_1=arr[row][col]+func(row+1, col);
            int op_2=arr[row][col]+func(row+1, col+1);
            return dp[row][col]=min(op_1, op_2);
        }
        */
        // tabulation: O(n) and sc: O(n*m) for dp array
        int n=triangle.size();
        int m=n;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // base case:
        // 1. when we have reached the bottom row
        // when row==n-1 col be anything
        for(int col=0; col<m; col++)
        {
            dp[n-1][col]=triangle[n-1][col];
        }
        // for loops
        for(int row=n-2; row>=0; row--)
        {
            for(int col=row; col>=0; col--)
            {
                // now we go for both options
                int op_1=triangle[row][col]+dp[row+1][col];
                int op_2=triangle[row][col]+dp[row+1][col+1];
                dp[row][col]=min(op_1, op_2);
            }
        }
        // so our destination is reaching the top row
        // and in our top row we have only one ele. so our ans is in 0th row and 0th col
        return dp[0][0];
    }
};
