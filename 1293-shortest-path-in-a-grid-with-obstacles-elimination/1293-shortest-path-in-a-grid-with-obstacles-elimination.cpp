class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // at any x,y ele on matrix i have 4 options to go ie up,down,l or r
        // this makes me think of recursion and then choose min of all the possibilities
        // which can be optimised using memoization, tabulation
        
        // but we can also think the coordinates of matrix as nodes of graph
        // and the paths as networks connecting those nodes
        // we can use bfs to find shortest path as we bfs us for that
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>> q;
        // queue contains {row, col, no of moves, k}
        q.push({0, 0, 0, k}); // at start we are at 0,0 ele with moves=0 and k=k
        // now a vector will store the no of k that we can still removed if we move thorugh a cell
        vector<vector<int>> visited(m, vector<int>(n, -1));
        // bfs
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it[0];
            int col=it[1];
            int moves=it[2];
            int curr_k=it[3];
            // if we reach our destination, we return moves
            if(row==m-1 && col==n-1) return moves;
            // base case if we go out of bounds
            if(row<0 || col<0 || row>=m || col>=n) continue;
            // now if we come across an obstacle
            if(grid[row][col]==1)
            {
                // if we have Ks we remove or else we continue as we cant go through this cell
                if(curr_k>0) curr_k--;
                else continue;
            }
            // now if we have already visited this cell
            // and we visited it with greater no of Ks previously
            // then we continue on this path as it costed us less Ks and we need to save Ks
            // for future use
            if(visited[row][col]!=-1 && visited[row][col]>=curr_k)
            {
                continue;
            }
            // update the visited with new Ks value
            visited[row][col]=curr_k;
            // now we go up, left, down and right
            // up
            q.push({row-1, col, moves+1, curr_k});
            // down
            q.push({row+1, col, moves+1, curr_k});
            // left
            q.push({row, col-1, moves+1, curr_k});
            // right
            q.push({row, col+1, moves+1, curr_k});
        }
        return -1; // if not possible
    }
};