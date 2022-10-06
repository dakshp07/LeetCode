class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // the main catch here is to use bfs rather than dfs
        // the reason to use bfs is we need to change the adjacent node at the same time
        // whereas in dfs due to recursion they get change one by one after each recursion call backtracks
        // apart from the grid val we will also keep a track of minutes in our queue
        // queue: {{i,j}, minutes}
        queue<pair<pair<int, int>, int>> q;
        // now we need to see the cases of fresh oranges still there, as we need -1 to be returned in that case
        // so we keep track of fresh ornages in grid
        int fresh=0;
        int tt=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1) fresh++;
                // now we push all rotten oranges in our grid to queue
                // as we check their adj nodes
                // time will be 0 as we are yet to start
                if(grid[i][j]==2) q.push({{i,j}, 0});
            }
        }
        // now we start bfs by peforming it till queue is empty
        while(!q.empty())
        {
            // now we pop and store the values
            auto it=q.front();
            q.pop();
            int x=it.first.first; // x coordinate
            int y=it.first.second; // y coordinate
            tt=it.second; // we store time as global var as we need to return it
            // now we go up,down,left,right and mark the fresh oranges as rotten
            
            // up
            if(x-1>=0 && grid[x-1][y]==1) // to check if are not out of bound and grid has fresh orange at this pos
            {
                // we push this ele on queue and also increment time by 1 as given in question
                q.push({{x-1, y}, tt+1});
                fresh--; // as now fresh count has decreased by one
                grid[x-1][y]=2; // we mark the grid as visited by making it 2 (rotten)
            }
            // down
            if(x+1<=grid.size()-1 && grid[x+1][y]==1) // to check if are not out of bound and grid has fresh orange at this pos
            {
                // we push this ele on queue and also increment time by 1 as given in question
                q.push({{x+1, y}, tt+1});
                fresh--; // as now fresh count has decreased by one
                grid[x+1][y]=2; // we mark the grid as visited by making it 2 (rotten)
            }
            // left
            if(y-1>=0 && grid[x][y-1]==1) // to check if are not out of bound and grid has fresh orange at this pos
            {
                // we push this ele on queue and also increment time by 1 as given in question
                q.push({{x, y-1}, tt+1});
                fresh--; // as now fresh count has decreased by one
                grid[x][y-1]=2; // we mark the grid as visited by making it 2 (rotten)
            }
            // right
            if(y+1<=grid[0].size()-1 && grid[x][y+1]==1) // to check if are not out of bound and grid has fresh orange at this pos
            {
                // we push this ele on queue and also increment time by 1 as given in question
                q.push({{x, y+1}, tt+1});
                fresh--; // as now fresh count has decreased by one
                grid[x][y+1]=2; // we mark the grid as visited by making it 2 (rotten)
            }
        }
        // now we return our tt if fresh==0
        // else we return -1
        return fresh==0 ? tt:-1; 
    }
};