class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // normal gyaan:
        // formula for calculating pascal triangle value for a given row r and col c is:
        // r-1 C c-1
        // where, nCr=n!/(n-r)!*r!
        
        // solution:
        // we just add the top two ele everytime
        // ie mat[r-1][c]+mat[r-1][c-1]
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++) // at max we will have numRows rows
        {
            // every row has i+1 ele, we intialize the array with 1s
            vector<int> row(i+1, 1);
            // now we traverse from 1st index till ith index as 0th index will always be 1 
            for(int j=1; j<i; j++)
            {
                // for any jth ele the value will be mat[r-1][c]+mat[r-1][c-1]
                row[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            // at the end we push every row to ans matrix
            ans.push_back(row);
        }
        return ans;
    }
};