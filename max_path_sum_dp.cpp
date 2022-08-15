
int getMaxPathSum(vector<vector<int>> &matrix)
{
    // so here we have variable starting points and variable ending points
    // lets peform recursion and try all paths
    /*
    recurion: tc: O(3^n) and sc: O(n)
    int func(int row, int col)
    {
    if(row==0) return arr[row][col]; // as we stop when we reach top row from last row
    if(col<0 || col>=m) return 1e9; // as we dont want to include this in path
    int up=arr[row][col]+func(row-1, col);
    int ldiag=arr[row][col]+func(row-1, col-1);
    int rdiag=arr[row][col]+func(row-1, col+1);
    return max(up, max(ldiag, rdiag));
    }
    int main()
    {
    for(int i=0; i<m; i++) // we call for all the ele of last row
    {
    int ans=func(n-1, i); // take every ele of last row and see 
    ans=max(ans, -infinity);
    }
    }
    
    memoization: tc: O(n*m) and sc: O(n*m) for array + O(n) for recursion stack space
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int func(int row, int col)
    {
    if(dp[row][col]!=-1) return dp[row][col];
    if(row==0) return arr[row][col]; // as we stop when we reach top row from last row
    if(col<0 || col>=m) return 1e9; // as we dont want to include this in path
    int up=arr[row][col]+func(row-1, col);
    int ldiag=arr[row][col]+func(row-1, col-1);
    int rdiag=arr[row][col]+func(row-1, col+1);
    return dp[row][col]=max(up, max(ldiag, rdiag));
    }
    */
    // tabulation: tc: O(n*m) + O(m) for maxi and sc: O(n*m) for array
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // base case
    for(int j=0; j<m; j++)
    {
        // when we at first row
        dp[0][j]=matrix[0][j];
    }
    // we solved 0 so we start from 1
    for(int i=1; i<n; i++)
    {
        // now j can start from 0 to n-1
        for(int j=0; j<m; j++)
        {
            int ldiag=matrix[i][j], rdiag=matrix[i][j];
            int up=matrix[i][j]+dp[i-1][j];
            if(j-1>=0) ldiag+=dp[i-1][j-1];
            else ldiag+=-1e9;
            if(j+1<m) rdiag+=dp[i-1][j+1];
            else rdiag+=-1e9;
            dp[i][j]=max(up, max(ldiag, rdiag));
        }
    }
    int maxi=-1e9;
    // now the calls will be made from all ele of last ele
    for(int j=0; j<m; j++)
    {
        maxi=max(maxi, dp[n-1][j]);
    }
    return maxi;
}
