int Solution::findMedian(vector<vector<int> > &A) {
    // brute force kya hoga, extra memory use karo and store matrix as array, sort the array
    // and then just return the middle element of that array
    // tc: O(N) for putting in array + O(N logN) to sort. total tc: O(NlogN) and sc: O(N)
    // but we aint allowed to use extra memory
    // we can efficiently apply binary search here
    // find the min, max element in matrix, we jst need to compare first, last ele of each row
    // a median will exist such that the no of ele smaller than it will be exactly n/2
    int r = A.size(), c = A[0].size();
    int mini = INT_MAX, maxi = INT_MIN;
    // find min, max in matrix
    for(int i = 0;i<r;i++){
        mini = min(mini, A[i][0]);
        maxi = max(maxi, A[i][A[i].size()-1]);
    }
    int low = mini, high = maxi, res = -1; // ans initialized as -1
    while(low<=high)
    {
        // our mid of low, high
        int mid = low+(high-low)/2;
        int desired=(r*c+1)/2; // our count of numbers that are less than median
        // lets look for count of numbers who are less than our mid
        int cnt=0;
         for(int i = 0;i<r;i++){
            cnt+=(upper_bound(A[i].begin(), A[i].end(), mid)-A[i].begin());
        }
        // if we have less cnt than desired we update our mi, mx
        if(cnt<desired){
            low = mid+1;
        }
        else{
            res = mid;
            high = mid-1;
        }
    }
    return res; // return either mi, mx anyone
}
