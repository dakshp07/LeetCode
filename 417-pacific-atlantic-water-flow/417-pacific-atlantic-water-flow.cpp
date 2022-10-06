class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>> &oceans, int row, int col)
    {
        // we mark them as visited since we can go to respective ocean with them
        oceans[row][col]=1;
        // now we go up, down, left, right
        // up
        if(row-1>=0 && heights[row][col]<=heights[row-1][col] && oceans[row-1][col]!=1)
        {
            dfs(heights, oceans, row-1, col);
        }
        // down
        if(row+1<heights.size() && heights[row][col]<=heights[row+1][col] && oceans[row+1][col]!=1)
        {
            dfs(heights, oceans, row+1, col);
        }
        // left
        if(col-1>=0 && heights[row][col]<=heights[row][col-1] && oceans[row][col-1]!=1)
        {
            dfs(heights, oceans, row, col-1);
        }
        // right
        if(col+1<heights[0].size() && heights[row][col]<=heights[row][col+1] && oceans[row][col+1]!=1)
        {
            dfs(heights, oceans, row, col+1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // so we just need to see the cells through which we can reach both pacific
        // and atlantic ocean, we can check for them both individually
        // return the common positions of both
        // and that will the ans
        // we use dfs to recursively check for adj grid nodes
        
        // these two bool vectors will makr nodes as true or false if they can reach oceans
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));               vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));
        
        // we check pacific first
        // now since pacific is just on left, top we go through them
        for(int i=0; i<heights.size(); i++)
        {
            // left row
            dfs(heights, pacific, i, 0);
        }
        // we go from i=1 as 0 was covered in before for loop
        for(int i=1; i<heights[0].size(); i++)
        {
            // top row
            dfs(heights, pacific, 0, i);
        }
        
        
        // we check atlantic now
        // now since atlantic is just on right, bottom we go through them
        for(int i=0; i<heights.size(); i++)
        {
            // bottom row
            dfs(heights, atlantic, i, heights[0].size()-1);
        }
        
        // we stop at -1 and not go there as its covered in before loop
        for(int i=0; i<heights[0].size()-1; i++)
        {
            // right row
            dfs(heights, atlantic, heights.size()-1, i);
        }
        vector<vector<int>> ans;
        // we push i,j to ans if pacific[i][j]==1 && atlantic[i][j]==1
        for(int i=0; i<heights.size(); i++)
        {
            for(int j=0; j<heights[0].size(); j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};