class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        // check the bounds
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==1) return;
        grid[row][col]=1; // mark visited
        // go left, right, top, bottom
        dfs(grid, row+1, col); // down
        dfs(grid, row-1, col); // up
        dfs(grid, row, col+1); // right
        dfs(grid, row, col-1); // left
    }
    int closedIsland(vector<vector<int>>& grid) {
        // we will use DFS to check the adj nodes
        // the boundary nodes are of no use
        // so we make them as 1 ie water
        int ans=0;
        // only boundary
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
                {
                    if(grid[i][j]==0)
                    {
                        dfs(grid, i, j);
                    }
                }
            }
        }
        // now we see dfs
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};