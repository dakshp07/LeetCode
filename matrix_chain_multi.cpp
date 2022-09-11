class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // for any ith matrix the dimensions are: arr[i]*arr[i-1]
        // so we follow the steps of writing a partition dp
        /*
        recursion: tc: O(exponential)
        int func(int i, int j)
        {
            // here i is at the starting of block 
            // j is the ending point of the block
            
            // base case
            if(i==j) return 0;
            // explore partitions
            int mini=1e9;
            for(int k=i; k<j; k++)
            {
            // since we need to get the matrix multiplication
            // 10*20 20*30 when multiplied gives a matrix of size 10*30
            // so we do the same thing in the first expression of steps
            // apart from this one we will have 2 more parttions one before the k and one after it, so we add them too
            int steps=(arr[i-1]*arr[k]*arr[j])+func(i, k)+func(k+1, j); 
            mini=min(steps, mini); // to return minimum steps
            }
            return mini;
        }
        
        memoization: tc: O(n*n*n) since we run it for 3 partitions and sc: O(n^2) + O(n) for recursive stack space 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int func(int i, int j)
        {
            if(dp[i][j]!=-1) return dp[i][j];
            // here i is at the starting of block 
            // j is the ending point of the block
            
            // base case
            if(i==j) return 0;
            // explore partitions
            int mini=1e9;
            for(int k=i; k<j; k++)
            {
            // since we need to get the matrix multiplication
            // 10*20 20*30 when multiplied gives a matrix of size 10*30
            // so we do the same thing in the first expression of steps
            // apart from this one we will have 2 more parttions one before the k and one after it, so we add them too
            int steps=(arr[i-1]*arr[k]*arr[j])+func(i, k)+func(k+1, j); 
            mini=min(steps, mini); // to return minimum steps
            }
            return dp[i][j]=mini;
        }
        */
        // tabulation:
        vector<vector<int>> dp(N, vector<int>(N, 0));
        // no need to right base case as we already intitialize the dp with 0
        for(int i=N-1; i>=1; i--)
        {
            for(int j=i+1; j<N; j++)
            {
                int mini=1e9;
                for(int k=i; k<j; k++)
                {
                    // since we need to get the matrix multiplication
                    // 10*20 20*30 when multiplied gives a matrix of size 10*30
                    // so we do the same thing in the first expression of steps
                    // apart from this one we will have 2 more parttions one before the k and one after it, so we add them too
                    int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j]; 
                    mini=min(steps, mini); // to return minimum steps
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }
};
