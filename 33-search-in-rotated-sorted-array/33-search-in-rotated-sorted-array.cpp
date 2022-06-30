class Solution {
public:
    int search(vector<int>& nums, int target) {
        // linear serach is  brute force
        // there will always be a section in the array which is sorted
        // tc: O(log n) and sc: O(1)
        int low=0, high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            // we will first find the part which is sorted
            if(nums[mid]>=nums[low]) // means the left half is sorted
            {
                if(nums[low]<=target && nums[mid]>=target) // means our target is b/w low and mid
                {
                    // then we will ask binary search to look in this range
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                // now we know that our right half is sorted
                if(nums[mid]<=target && nums[high]>=target) // means our target is b/w low and mid
                {
                    // then we will ask binary search to look in this range
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};