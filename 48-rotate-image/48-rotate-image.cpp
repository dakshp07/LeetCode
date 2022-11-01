class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // basicallu we do a transpose
        // and then reverse every row
        // ex: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        // transpose: [[1,4,7], [2,5,8], [3,6,9]]
        // reverse every row: [[7,4,1], [8,5,2], [9,6,3]]
        // which is our desired result
        
        // transpose
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse every row
        for(int i=0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};