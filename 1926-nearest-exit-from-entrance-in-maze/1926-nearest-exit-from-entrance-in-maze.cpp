class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // so as we need to return the ans when we reach nearest exit, we think of bfs
        // dfs ie recursion can be used as well which can be further optimised to memoization
        
        int m=maze.size(); // row
        int n=maze[0].size(); // col
        // we will use maze itself as visited array and mark the visited ele in it by +
        // queue will store {steps, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        // we mark current position of entrace as visited
        maze[entrance[0]][entrance[1]]='+';
        // and also push them into queue, with steps as 0
        q.push({0, {entrance[0], entrance[1]}});
        // bfs
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.second.first;
            int col=it.second.second;
            int steps=it.first;
            // now we check for some cases
            // case 1: if we are at boundary but its the entrace point, then we skip it
            if(row==0 || col==n-1 || row==m-1 || col==0)
            {
                if(row==entrance[0] && col==entrance[1]) ;
                // case 2: if we are at boundary but its not the entrance point, then we return steps
                else
                {
                    return steps;
                }
            }
            // now we go up, down, left and right only and only if dont go out of bounds and we dont hit a wall
            // up
            if(row-1>=0 && maze[row-1][col]=='.') 
            {
                q.push({steps+1, {row-1, col}});
                maze[row-1][col]='+';
            }
            // down
            if(row+1<m && maze[row+1][col]=='.') 
            {
                q.push({steps+1, {row+1, col}});
                maze[row+1][col]='+';
            }
            // left
            if(col-1>=0 && maze[row][col-1]=='.') 
            {
                q.push({steps+1, {row, col-1}});
                maze[row][col-1]='+';
            }
            // right
            if(col+1<n && maze[row][col+1]=='.') 
            {
                q.push({steps+1, {row, col+1}});
                maze[row][col+1]='+';
            }
        }
        // if we dont reach any exit we return -1
        return -1;
    }
};