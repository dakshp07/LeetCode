class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we will use BFS here beacuse in BFS we first visit all adj nodes
        // whereas in DFS we call adj node, they call their adj nodes and so on
        // here the rooten ornage destroys the adj ones first, then destroy next one
        queue<pair<pair<int, int>, int>> q; // stores i, j and current time
        int fresh=0; // we store fresh count
        int time=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1) fresh++; // keep fresh orange count
                if(grid[i][j]==2) q.push({{i, j}, 0}); // as we are yet to visit adj node so time=0
            }
        }
        // BFS
        while(!q.empty())
        {
            // get all the values from the front of queue
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            time=it.second;
            q.pop();
            // we go up, down, left, right to check the fresh ones and make them rotten
            // at the same time we decrease the value of fresh orange
            
            if(row!=grid.size()-1 && grid[row+1][col]==1) // down
            {
                fresh--; // decrement fresh
                grid[row+1][col]=2; // mark grid as visited
                q.push({{row+1, col}, time+1}); // push to queue as we do in BFS and also add time+1
            }
            if(row!=0 && grid[row-1][col]==1) // up
            {
                fresh--; // decrement fresh
                grid[row-1][col]=2; // mark grid as visited
                q.push({{row-1, col}, time+1}); // push to queue as we do in BFS and also add time+1
            }
            if(col!=grid[0].size()-1 && grid[row][col+1]==1) // right
            {
                fresh--; // decrement fresh
                grid[row][col+1]=2; // mark grid as visited
                q.push({{row, col+1}, time+1}); // push to queue as we do in BFS and also add time+1
            }
            if(col!=0 && grid[row][col-1]==1) // left
            {
                fresh--; // decrement fresh
                grid[row][col-1]=2; // mark grid as visited
                q.push({{row, col-1}, time+1}); // push to queue as we do in BFS and also add time+1
            }
        }
        // if there are still some fresh oranges then we say -1
        if(fresh!=0) return -1;
        return time; // if no fresh oranges then we return our total time
    }
};