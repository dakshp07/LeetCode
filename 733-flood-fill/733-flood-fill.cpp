class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int current_color, int target_color)
    {
        // base case
        // 1. out of bounds
        // 2. not with color same as previous
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=current_color) return;
        // now we color this ele
        image[sr][sc]=target_color;
        // we go up, down, left, right
        dfs(image, sr-1, sc, current_color, target_color);
        dfs(image, sr+1, sc, current_color, target_color);
        dfs(image, sr, sc-1, current_color, target_color);
        dfs(image, sr, sc+1, current_color, target_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // so essentially we need to change color of all the 4 direction elements in grid which have same color as grid[sr][sc]
        // we can do a dfs or bfs
        // but i will try dfs here
        int current_color=image[sr][sc];
        int target_color=color;
        if(current_color!=target_color) // we pick node if its current color isnt same as target color
        {
            dfs(image, sr, sc, current_color, target_color);
        }
        return image;
    }
};
