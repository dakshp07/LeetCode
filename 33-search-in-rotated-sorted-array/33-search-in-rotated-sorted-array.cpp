class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length=nums.size();
        int left=0;
        int right=length-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        int start=left;
        left=0;
        right=length-1;
        if(target>=nums[start] && target<=nums[right])
        {
            left=start;
        }
        else
        {
            right=start;
        }
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            if(nums[mid]<target)
            {
                left=mid+1;
            }
        }
        return -1;
    }
};