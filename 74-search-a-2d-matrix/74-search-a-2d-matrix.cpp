class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // linear search laga lo, O(N^2)
        // binary laga kon every row, so N rows, O(N*(logN))
        // todha zyaada aacha binary:
        // 1) consider this matrix as a linear array, but we wont use extra space
        // 2) now we will use the index to search elements
        // 3) O(log(N*M)) M=no of cols
        int n=matrix.size(); // rows
        int m=matrix[0].size(); // cols
        int low=0, high=(n*m)-1; // finding the index as they will be in 1D array
        while(low<=high)
        {
            int mid=(low+(high-low)/2); // setting mid
            if(matrix[mid/m][mid%m]==target) // now to get correct row and col, we use mid/m to get row and mid%m to get col no (formula hain, remeber)
            {
                return true;
            }
            // adjust boundries just like we do in 1D array
            if(matrix[mid/m][mid%m]>target)
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