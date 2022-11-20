class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if we find target we return mid
        // if we dont find target we return left beacuse we need to keep the target at the veru first positon where it can be inserted
        int left=0;
        int right=nums.size()-1;
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
        return left;
    }
};
