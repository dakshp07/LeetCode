class Solution {
public:
    int bs_left(vector<int> &nums, int target)
    {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(low==nums.size() || nums[low]!=target) return -1;
        return low;
    }
    int bs_right(vector<int> &nums, int target)
    {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(high<0 || nums[high]!=target) return -1;
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // ek toh hain ki sort and return the indexes. tc: O(n) and sc: O(1)
        // binary laga lo, to find the index. tc: O(log n) and sc: O(1)
        vector<int> ans(2, 0);
        ans[0]=bs_left(nums, target);
        ans[1]=bs_right(nums, target);
        return ans;
    }
};