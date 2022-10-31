class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we can keep three pointers
        // named as left,mid,right
        // 0 to left contains all 0s
        // left+1 to mid conatins all 1s
        // and mid+1 to right contains all 2s
        // if we see any number not in their respective zone, we swap them up
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        while(mid<=right)
        {
            // there could be 3 cases
            // 1. when nums[mid]==0
            // 2. when nums[mid]==1
            // 3. when nums[mid]==2
            
            // case 1
            if(nums[mid]==0)
            {
                // since all 0s are at 0 to left
                // so we swap
                swap(nums[left], nums[mid]);
                // and move both pointers forward
                left++;
                mid++;
            }
            // case 2
            else if(nums[mid]==1)
            {
                // since all 1s should be at left+1 to mid
                // we do nothing as this 1 is at correct position
                // just move the pointer forward
                mid++;
            }
            // case 3
            else if(nums[mid]==2)
            {
                // since all 2s should be at mid+1 to right
                // we swap
                swap(nums[mid], nums[right]);
                // and move pointers, basically right goes left
                right--;
            }
        }
    }
};