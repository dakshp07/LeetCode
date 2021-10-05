class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int length=grid.size();
        int count=0;
        for(int i=0; i<length; i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]<0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};