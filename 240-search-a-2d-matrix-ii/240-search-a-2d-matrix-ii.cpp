class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute is to go through all ele linearly
        // tc: O(row*col) and sc: O(1)
        
        // since we know its sorted we use bs
        // we start from top right,bottom left corner
        // the reason to that is: lets say our traget is >top right
        // then we know we can skip that entire row as the ele are sorted from left to right
        int m=matrix.size();
        int n=matrix[0].size();
        int row=0; // top
        int col=n-1; // bottom
        while(row<m && col>=0)
        {
            if(matrix[row][col]==target) return true;
            // means if our top right ele is smaller than target
            else if(target>matrix[row][col])
            {
                // we skip the entire row and move down
                // as in col the ele are sorted from top to bottom
                row++;
            }
            // means if our top right ele is bigger than target
            else if(target<matrix[row][col])
            {
                // means we can go and search in this column
                // so we move in this col
                col--;
            }
        }
        return false; // if not found
    }
};