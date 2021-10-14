class Solution {
public:
   int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n= matrix[0].size();
        int l=matrix[0][0];
        int r= matrix[m-1][n-1];
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(count(matrix,mid)>=k) {ans=mid; r=mid-1;}
            else l= mid+1;
        }
        return ans;
        }
        
    int count(vector<vector<int>>& matrix,  int target){
        int m=matrix.size();
         int n= matrix.size();
        int r=0;
        int c=n-1;
        int count=0;
        for (int r = 0; r < m; ++r) {
           while (c >= 0 && matrix[r][c] > target) --c;  
            count += (c + 1);
        }
     return count;
    }
};