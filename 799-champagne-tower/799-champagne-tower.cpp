class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // lets simulate the whole process
        vector<vector<double>> cham(101, vector<double>(101, 0));
        cham[0][0]=(double)poured;
        for(int i=0; i<=query_row; i++) // row
        {
            for(int j=0; j<=i; j++) // col
            {
                double fill=(cham[i][j]-1.0)/2.0;
                if(fill>0)
                {
                    cham[i+1][j]+=fill;
                    cham[i+1][j+1]+=fill;
                }
            }
        }
        double ans=min(cham[query_row][query_glass], 1.0);
        return ans;
    }
};