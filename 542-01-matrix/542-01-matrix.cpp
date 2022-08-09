class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // we do a BFS
        // and store row, col, dis in the queue
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j]==0) q.push({{i, j}, 0}); // since 0 node is at dis 0
                else mat[i][j]=-1; // else we make them -1
            }
        }
        // BFS
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            
            // we go up
            if(row-1>=0 && mat[row-1][col]==-1)
            {
                mat[row-1][col]=dis+1; // +1 then its adj node
                q.push({{row-1, col}, dis+1}); // push in queue
            }
            
            // we go down
            if(row+1<mat.size() && mat[row+1][col]==-1)
            {
                mat[row+1][col]=dis+1; // +1 then its adj node
                q.push({{row+1, col}, dis+1}); // push in queue
            }
            
            // we go left
            if(col-1>=0 && mat[row][col-1]==-1)
            {
                mat[row][col-1]=dis+1; // +1 then its adj node
                q.push({{row, col-1}, dis+1}); // push in queue
            }
            
            // we go right
            if(col+1<mat[0].size() && mat[row][col+1]==-1)
            {
                mat[row][col+1]=dis+1; // +1 then its adj node
                q.push({{row, col+1}, dis+1}); // push in queue
            }
        }
        return mat;
    }
};