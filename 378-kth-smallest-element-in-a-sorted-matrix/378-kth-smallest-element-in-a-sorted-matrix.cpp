class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // one of the way is to use a min heap, store ele and return the kth ele
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=0; i<matrix.size(); i++)
        // {
        //     for(int j=0; j<matrix[i].size(); j++)
        //     {
        //         pq.push(matrix[i][j]);
        //     }
        // }
        // k--;
        // while(k!=0)
        // {
        //     pq.pop();
        //     k--;
        // }
        // return pq.top();
        // tc: O(n^2*log n) to put in heap + O(k-1*log n) to remove + O(1) for peek
        // sc: O(n^2) for heap
        
        // since the array is sorted we can use binary search
        // tc: O(log n) sc: O(1)
        int low=matrix[0][0]; // first element
		int high=matrix[matrix.size()-1][matrix.size()-1]; // Last element
        int col, cnt;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // For each row count the elements that are smaller than mid
            col=matrix.size()-1; // start from last col and reach till first as the row are in ascending
            cnt=0;
            for(int i=0; i<matrix.size(); i++)
            {
                while(col>=0 && matrix[i][col]>mid)
                {
                    col--;
                }
                // col has the cnt of the ele smaller than mid
                cnt+=(col+1);
            }
            // now if cnt < k
            // which means we have to go beyond mid to get the kth ele
            if(cnt<k) 
            {
                low=mid+1;
            }
            // else we go behind
            else  if(cnt>=k)
            {
                high=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};