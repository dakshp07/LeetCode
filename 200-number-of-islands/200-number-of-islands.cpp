class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        // base case of dfs
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='0') return;
        // we mark the visited nodes as 0 so that we dont count them again
        grid[i][j]='0';
        // we go
        // up
        dfs(i-1, j, grid);
        // down
        dfs(i+1, j, grid);
        // left
        dfs(i, j-1, grid);
        // right
        dfs(i, j+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        // so we can run a dfs for all ele which are having 1
        // and go up,down,left,right to see how many of them are surronded by more adj nodes as 1
        int ans=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                // we peform dfs if the node is 1
                if(grid[i][j]=='1')
                {
                    dfs(i, j, grid);
                    // our dfs will return here once it has visited all adj nodes that has 1 for this grid[i][j]
                    // so now we have an island
                    // so we increment ans
                    ans++;
                }
            }
        }
        return ans;
    }
};