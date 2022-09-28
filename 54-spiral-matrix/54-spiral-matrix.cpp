class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        // we keep 4 variable
        int top, bottom, left, right;
        // top is at the first row
        // bottom is at last row
        // left is first col
        // right is last col
        top=0, bottom=n-1;
        left=0, right=m-1;
        // now a variable to keep track of direction
        int direction=1; // the 4 values 1,2,3,4 will show the 4 different directions that we need
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left; i<=right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                direction=2;
                top++;
            }
            else if(direction==2)
            {
                for(int i=top; i<=bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                direction=3;
                right--;
            }
            else if(direction==3)
            {
                for(int i=right; i>=left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                direction=4;
                bottom--;
            }
            else if(direction==4)
            {
                for(int i=bottom; i>=top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                direction=1;
                left++;
            }
        }
        return ans;
    }
};