class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we will use binary search
        // but with a formula to make sure that we can consider this matrix as linear array
        // tc: O(log(n*m)) where n,m are no of rows,cols
        /*
        The problem statement states that the values of the last col of the ith row is
        greater than the first col of (i+1)th row. Also, each row is sorted.
        This means that, if we linearly arrange the elements of each row, we will have a
        sorted array. So we can now perform a binary search over it.
        How will the matrix behave like an array without actually creating an auxiliary
        array?
        It could be achieved by the following formula :
        - A n * m matrix converted into an array: matrix[x][y] : a[x * m + y]
        - An array can be converted into n * m matrix: a[x] : matrix[x / m][x % m]
        */
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // formula for getting the index of matrix is: matrix[mid/m][mid%m]
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(matrix[mid/m][mid%m]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }
};