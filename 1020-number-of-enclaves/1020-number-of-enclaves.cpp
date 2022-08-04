class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0) return;
        grid[row][col]=0; // visited
        dfs(grid, row+1, col); // down
        dfs(grid, row-1, col); // up
        dfs(grid, row, col+1); // right
        dfs(grid, row, col-1); // left
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        // mark the 1s in the boundary as 0s since they are of no use
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1)
                {
                    if(grid[i][j]==1)
                    {
                        // we make all the touched nodes of boundary nodes as 0
                        // since they are not enclave
                        dfs(grid, i, j);
                    }
                }
            }
        }
        // now we count the no of 1s that are left in grid
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};