class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int &area)
    {
        // we check if row, col are out od bound or not
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0)
        {
            return;
        }
        grid[row][col]=0; // mark them as 0 so that we dont visit them again
        area++; // increase the area by 1
        // we will go left, right, top, down
        dfs(grid, row+1, col, area); // down
        dfs(grid, row-1, col, area); // up
        dfs(grid, row, col-1, area); // left
        dfs(grid, row, col+1, area); // right
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // we just need to return the no of 1s adj
        // we will use DFS traversal
        int max_area=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(grid, i, j, area);
                    max_area=max(max_area, area);
                }
            }
        }
        return max_area;
    }
};