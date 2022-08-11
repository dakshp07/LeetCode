class Solution {
public:
    int uniquePaths(int m, int n) {
        // ek toh hain ki brute force karo
        // recursively try hands around by going down and going right
        // the answer to both will add up to give final ans
        // tc will be exponantial, its recursion
        // dp ka use karlo or todhe states save karo while recursion, n*m ki tc or n*m ka sc
        // todha or optimise kar paayege if we use PnC
        // video dekho striver ka for approach
        // int total=n+m-2;
        // int r=m-1;
        // double res=1;
        // for(int i=1; i<=r; i++)
        // {
        //     res=res*(total-r+i)/i;
        // }
        // return res;
        
        // recursion: tc: O(2^m*n) and sc: O(path length) as stack space for recusion
        /*
        int fun(int row, int col)
        {
        if(row==0 && col==0) means we reached (0, 0)
        {
        return 1;
        }
        if(row<0 || col<0) return 0; if we reach out of bounds
        int up=func(row-1, col); // go up
        int left=func(row, col-1);
        return left+up;
        }
        
        // lets do memoization: O(m*n) and sc: O(path length) as stack space for recusion + O(n*m) for dp array
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int row, int col, vector<int> &dp)
        {
        if(row==0 && col==0) means we reached (0, 0)
        {
        return 1;
        }
        if(row<0 || col<0) return 0; if we reach out of bounds
        if(dp[row][col]!=-1) return dp[row][col];
        int up=func(row-1, col); // go up
        int left=func(row, col-1);
        return dp[row][col]=left+up;
        }
        */
        // lets try tabulation: tc: O(n*m) and sc: O(n*m) just for array
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // dp[i][j] stored the no of path to reach the node (i, j)
        dp[0][0]=1; // if we are at index (0, 0) theres just one way
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int up=0, left=0;
                if(i==0 && j==0) dp[i][j]=1; // of we are at (0,0)
                // we go up and left
                else
                {
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left; // add up, left to dp[i][j]
                }
            }
        }
        return dp[n-1][m-1];
    }
    /*
    // space optimization: tc: O(m*n) and sc: O(n) as we use one n size array
    we see that we are using row-1 and col-1 again and again
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
    */
};