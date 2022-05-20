class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //simple kaam phele
        // store row and col of ele ie is 0
        set<int> rows, cols; // set isliye taaki .fnnd use kar sake
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        // 1 more iteration, check with sets and make that row and col element as zero
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};