class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int &area)
    {
        // base case
        // 1. if we go out of bounds
        // 2. if we see a zero
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0) return;
        // we mark this ele as 0, so as to not count it twice
        // essentially i'm using my grid as a seen array itself
        grid[row][col]=0;
        // we do area+1 now
        area++;
        // now we go up, down, left, right
        dfs(grid, row-1, col, area);
        dfs(grid, row+1, col, area);
        dfs(grid, row, col-1, area);
        dfs(grid, row, col+1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // so we need to find a group of 1s and see if we can make a group of them by checking if any 1s are 4 directionally covered with 1s
        // we peform a dfs or bfs
        // i will try to do a dfs
        int ans=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                int area=0; // we start with area as 0 for every ele
                if(grid[i][j]!=0) // we will visit this ele only if its 1
                {
                    dfs(grid, i, j, area);
                    // we pick max of all area
                    ans=max(ans, area);
                }
            }
        }
        return ans;
    }
};
