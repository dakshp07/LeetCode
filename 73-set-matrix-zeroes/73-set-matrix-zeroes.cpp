class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // set use karte hain
        // will store the index of row, col where ele is 0
        set<int> rows, cols;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j]==0) // if an ele is 0
                {
                    rows.insert(i); // row ke index ko daalo rows main
                    cols.insert(j); // col ke index ko daalo cols main
                }
            }
        }
        // now traverse again
        // look for the row, col in both the sets respectively
        // if the row or col is in set then make that ele as 0
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end()) // if that index is part of any of the two sets
                {
                    matrix[i][j]=0; // we make that ele as 0
                }
            }
        }
    }
};