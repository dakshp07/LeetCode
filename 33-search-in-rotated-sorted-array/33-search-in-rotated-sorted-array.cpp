class Solution {
public:
    int search(vector<int>& nums, int target) {
        // always remember there will always be a part in the entire array which will remain sorted
        // so we need to identify that part and apply binary search for that part
        // tc: O(log n)
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            // now we check which half is sorted
            // what if left half is sorted?
            if(nums[mid]>=nums[low])
            {
                // if nums[mid]>nums[low] means the left half is sorted
                // so we check on this half
                if(nums[mid]>=target && nums[low]<=target)
                {
                    // if nums[mid] is > and nums[low] <
                    // means our ans is somewhere b/w low and mid
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            // what is right half is sorted instead of left one
            else
            {
                if(nums[mid]<=target && nums[high]>=target)
                {
                    // if nums[mid] is < and nums[high] >
                    // means our ans is somewhere b/w high and mid
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