class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // formula for calculating pascal triangle value for a given row r ad col c is:
        // r-1 C c-1
        // where, nCr=n!/(n-r)!*r!
        vector<vector<int>> res(numRows);
        for(int i=0; i<numRows; i++)
        {
            res[i].resize(i+1);
            res[i][0]=res[i][i]=1;
            for(int j=1; j<i; j++)
            {
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};