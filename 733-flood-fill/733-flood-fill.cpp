class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int target_color, int prev_color)
    {
        // base case for dfs
        if(sr>=image.size() || sc>=image[0].size() || sr<0 || sc<0 || image[sr][sc]!=prev_color) return;
        // now we make this node as target color
        image[sr][sc]=target_color;
        // and move
        // up
        dfs(image, sr-1, sc, target_color, prev_color);
        // down
        dfs(image, sr+1, sc, target_color, prev_color);
        // left
        dfs(image, sr, sc-1, target_color, prev_color);
        // right
        dfs(image, sr, sc+1, target_color, prev_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // we will peform a simple dfs on the matrix
        // we pick up the ele at (sr,sc) and then look for all other neighboring nodes which has same color as the node at (sr, sc)
        // and mark them with target color
        
        // we peform a dfs only if the node is not of target color already
        int prev_color=image[sr][sc];
        if(prev_color!=color)
        {
            dfs(image, sr, sc, color, prev_color);
        }
        return image;
    }
};
