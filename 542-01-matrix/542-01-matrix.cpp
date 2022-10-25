class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // one of the ways will be to store
        // coordinates of all 0s and then for every i,j ele we iterate our all these 0s
        // and then store the minimum dis
        // tc: O(n*m) for storing zero + O((n*m)^2) to iterate over all the possibilties
        
        // the other that i can think is bfs
        // we return the same matrix as our ans
        // so we first all 1s in matrix as -1 and then update them with their distance as we move for our bfs
        // queue stores row,col and distance
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[i].size(); j++)
            {
                if(mat[i][j]==0)
                {
                    // we push all 0s in queue
                    // queue: {{i,j},0} 0 is the dis since all 0s are at a dis of 0
                    q.push({{i, j}, 0});
                }
                // we mark all 1s with dis as -1
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        // now we run BFS
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            // now we go up, down, left and right
            // apart from bounds we check if the coordinate is not visited or not
            // we check that by seeing if mat==-1 or not, if it is -1 we go and do bfs
            // up
            if(row-1>=0 && mat[row-1][col]==-1)
            {
                // now this ele will be at a distance of dis+1
                // so we push it accordingly
                q.push({{row-1, col}, dis+1});
                // and also update the ele with new dis
                mat[row-1][col]=dis+1;
            }
            // down
            if(row+1<=mat.size()-1 && mat[row+1][col]==-1)
            {
                // now this ele will be at a distance of dis+1
                // so we push it accordingly
                q.push({{row+1, col}, dis+1});
                // and also update the ele with new dis
                mat[row+1][col]=dis+1;
            }
            // left
            if(col-1>=0 && mat[row][col-1]==-1)
            {
                // now this ele will be at a distance of dis+1
                // so we push it accordingly
                q.push({{row, col-1}, dis+1});
                // and also update the ele with new dis
                mat[row][col-1]=dis+1;
            }
            // right
            if(col+1<=mat[0].size()-1 && mat[row][col+1]==-1)
            {
                // now this ele will be at a distance of dis+1
                // so we push it accordingly
                q.push({{row, col+1}, dis+1});
                // and also update the ele with new dis
                mat[row][col+1]=dis+1;
            }
        }
        return mat;
    }
};