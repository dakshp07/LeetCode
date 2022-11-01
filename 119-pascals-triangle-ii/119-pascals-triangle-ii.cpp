class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // we use all logic of pascal triangle i
        // we return just an index of ans instead of returning entire vector<vector<int>>
        vector<vector<int>> ans;
        for(int i=0; i<rowIndex+1; i++) // we go till rowIndex+1 as we need to return rowIndex
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
        return ans[rowIndex];
    }
};