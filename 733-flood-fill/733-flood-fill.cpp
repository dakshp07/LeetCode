class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int prev_color, int target_color)
    {
        // we first check the indexes are not out of bound
        if(sr>=0 && sc>=0 && sr<image.size() && sc<image[0].size())
        {
            // we check if the color is prev color
            if(image[sr][sc]==prev_color)
            {
                // we color this cell
                image[sr][sc]=target_color;
                // and also fill adj cells
                dfs(image, sr+1, sc, prev_color, target_color);
                dfs(image, sr, sc-1, prev_color, target_color);
                dfs(image, sr-1, sc, prev_color, target_color);
                dfs(image, sr, sc+1, prev_color, target_color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // we can peform a DFS or a BFS on the matrix
        // lets try a DFS
        if(image[sr][sc]!=color)
        {
            dfs(image, sr, sc, image[sr][sc], color); // prev color is the existing color the cell has and the target is the one given
        }
        return image;
    }
};