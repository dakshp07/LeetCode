class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1 || grid[grid.size()-1][grid.size()-1]==1)
        {
            return -1;
        }
        // we can use recursion and then memoization which is dfs
        // but we will try to use bfs here
        // as bfs is used to get the shortest path
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1}); // queue has: {{row, col}, dis}
        // we push 0,0 as we start from there and with a dis of 1
        // dis will be 1 as we need to count top left ie (0,0) cell as well
        // bfs
        while(!q.empty())
        {
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int dis=it.second;
            q.pop();
            if(row==grid.size()-1 && col==grid.size()-1) return dis;
            // now we go up,down,left,right,and 4 diagonals
            // up
            if(row-1>=0 && grid[row-1][col]!=1)
            {
                q.push({{row-1, col}, dis+1});
                grid[row-1][col]=1;
            }
            // down
            if(row+1<grid.size() && grid[row+1][col]!=1)
            {
                q.push({{row+1, col}, dis+1});
                grid[row+1][col]=1;
            }
            // left
            if(col-1>=0 && grid[row][col-1]!=1)
            {
                q.push({{row, col-1}, dis+1});
                grid[row][col-1]=1;
            }
            // right
            if(col+1<grid.size() && grid[row][col+1]!=1)
            {
                q.push({{row, col+1}, dis+1});
                grid[row][col+1]=1;
            }
            // diag down left
            if(row+1<grid.size() && col-1>=0 && grid[row+1][col-1]!=1)
            {
                q.push({{row+1, col-1}, dis+1});
                grid[row+1][col-1]=1;
            }
            // diag down right
            if(row+1<grid.size() && col+1<grid.size() && grid[row+1][col+1]!=1)
            {
                q.push({{row+1, col+1}, dis+1});
                grid[row+1][col+1]=1;
            }
            // diag top left
            if(row-1>=0 && col-1>=0 && grid[row-1][col-1]!=1)
            {
                q.push({{row-1, col-1}, dis+1});
                grid[row-1][col-1]=1;
            }
            // diag top right
            if(row-1>=0 && col+1<grid.size() && grid[row-1][col+1]!=1)
            {
                q.push({{row-1, col+1}, dis+1});
                grid[row-1][col+1]=1;
            }
        }
        return -1;
    }
};
