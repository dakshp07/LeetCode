class Solution {
public:
    int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
    
    // boundary cross check
    if( j1<0 || j2<0 || j1>=c || j2>=c){
        return (int)-1e9;
    }
    
    // reached last row
    if(i == r-1){
        
        if(j1 == j2)
        {    // alice and bob ended up in same column so return one column
            return grid[i][j1];
        }
        else{  // ended up in different columns
            return grid[i][j1] + grid[i][j2] ;
        }
    }
    
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }
     //EXPLORE ALL PATHS OF ALICE AND BOB SIMULTANEOUSLY
    int maxi = (int)-1e9;
    int dy[] = {-1,+0,+1};
    // dj1 = alice direction
    // dj2 = bob's direction
    for(int dj1 = -1 ;dj1 <= +1; dj1++){
        for(int dj2 = -1 ;dj2 <= +1;dj2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }
            else{
                value = grid[i][j1] + grid[i][j2];
            }
            value+=solve(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi = max(maxi,value);
        }
    }
    
    return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        // fixed starting point but variable ending point
        // so we need to generate all the paths for robot 1 and robot 2
        // we need to make sure that the recursion goes together because in case of common cell we need to consider that cell just once
        // so the recursion will now have (i1, j1) && (i2, j2) one for robo1 and other for robo2
        // but they start from same row, so we just need one i and two j's
        // recursion: tc: O(3^n * 3^n) as robo1 has 3 option and robo2 has 3 options and sc: O(n) stack space
        /*
        int func(int i, int j1, int j2)
        {
        // if we go out of bound
        if(j1<0 || j1>=m || j2<0 || j2<m) return -1e9;
        if(i==n-1)
        {
        // we see if they reach same cols or diff cols
        // if they reach same col then we add the value once or else we add twice
        if(j1==j2) return arr[i][j1];
        else return arr[i][j1]+arr[i][j2];
        // for every one moment of robo1 there are 3 movements of robo2 and same for tobo1 for every move of robo2
        // in total: 9 combos
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++) { // these two loops cover all 9 combos
        for (int dj = -1; dj <= 1; dj++) {
        int ans;
        if (j1 == j2) // we add once when the are at same col
        ans = grid[i][j1] + func(i+1, j1+di, j2+dj, n, m, grid, dp);
        else
        ans = grid[i][j1] + grid[i][j2] + func(i+1, j1+di, j2+dj, n, m, grid, dp);
        maxi = max(maxi, ans);
        }
        }
        return maxi;
        }
        }
        
        // memoization: tc: O(n*m*m*9) and sc: O(n*m*m) for array + O(n) for recursion 
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        int func(int i, int j1, int j2)
        {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;
        if (i == n - 1) 
        {
        if (j1 == j2)
        return grid[i][j1];
        else
        return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
        int maxi = INT_MIN;
        for(int di = -1; di <= 1; di++){
        for (int dj = -1; dj <= 1; dj++) {
        int ans;
        if (j1 == j2)
        ans = grid[i][j1]+func(i+1, j1+di, j2+dj, n, m, grid);
        else
        ans = grid[i][j1]+grid[i][j2]+func(i+1, j1+di, j2+dj, n, m, grid);
        maxi = max(maxi, ans);
        }
        }
        return dp[i][j1][j2] = maxi;
        }
        */
        // tabulation
        int r = grid.size();
        int c = grid[0].size();
        // initially 
        // Alice is at (i = 0, j1 = 0) and Bob is at (i = 0,j2 = c-1) 
        int i = 0;
        int j1 = 0;
        int j2 = c- 1;
        // dp[r][c][c]
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1))); //dp[][][]
        return solve(i,j1,j2,r,c,grid,dp);
    }
};