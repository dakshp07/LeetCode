class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==-1)
        {
            return false;
        }
        if(arr[start]==0)
        {
            return true;
        }
        int right=start+arr[start];
        int left=start-arr[start];
        arr[start]=-1;
        return left=(right<arr.size() && canReach(arr, right)) || (left>=0 && canReach(arr, left));
    }
};