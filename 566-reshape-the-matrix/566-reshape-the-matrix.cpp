class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // we just create a new matrix of size r,c and fill it with ele
        // tc: O(n*m) and sc: O(r*c)
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        // if its not possible to fit all ele of mat in new matrix we return mat
        if(r*c!=n*m) return mat;
        // we keep two pointer
        // row and col ptr we increment them according to situation
        int row=0, col=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[row][col]=mat[i][j];
                // since we fill columns first, we increment col ptr
                col++;
                // if we reach the last col
                // means now we need to go to next row
                if(col==c)
                {
                    // go to next row
                    row++;
                    // since its new row we start from col=0 only
                    col=0;
                }
            }
        }
        return ans;
    }
};