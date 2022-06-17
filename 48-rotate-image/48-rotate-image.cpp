class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose karo
        // phir every row ko individually reverse maardo
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]); // making rows to go to column
            }
        }
        // now reverse every row
        for(int i=0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};