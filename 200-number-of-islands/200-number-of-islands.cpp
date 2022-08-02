class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        // we check if we dont go out of bounds
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0') return;
        
        // mark this ele as visited by making it 0
        grid[row][col]='0';
        
        dfs(grid, row+1, col); // down
        dfs(grid, row-1, col); // up
        dfs(grid, row, col+1); // right
        dfs(grid, row, col-1); // left
    }
    int numIslands(vector<vector<char>>& grid) {
        // an island is the piece of land which is connected with each other in vertical & horizontal direction
        // we will do a DFS/BFS and see how many islands are there, i will use DFS
        // there are chances when the vertical, horizontal coordinate have 1s as well
        // so in DFS if we are at row r, col c then we make 4 calls
        // 1. row+1, col 2. row-1, col. 3. row, col+1 4. row, col-1
        // we will also mark the visted ele as 2 to make sure we dont visit them again
        int ans=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                // we peform DFS only if that ele is 1
                if(grid[i][j]=='1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};