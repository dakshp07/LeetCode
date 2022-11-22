class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // one way is to count number of 0s in nums
        // create another array and put all 0s in end and rest numbers at respective pos
        // tc: O(n) and sc: O(n)
        
        // but we use two pointers approach
        // we keep left, right at 0 and iterate till we reach end ie right<nums.size()
        int left=0;
        int right=0;
        while(right<nums.size())
        {
            // if nums[right]==0 then we dont do swapping as we need 0s at end
            // we just move right
            if(nums[right]==0) right++;
            // if nums[right]!=0 we need to swap it and move both left, right
            else
            {
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
        }
    }
};