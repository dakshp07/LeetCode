class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we simly use kadane
        // we either take the max(curr_ele, sum+curr_ele);
        int curr=nums[0];
        int sum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            // our curr will be either curr+nums[i] or nums[i]
            curr=max(nums[i]+curr, nums[i]);
            // and sum will be either the sum that we have already seen ie curr or the sum
            sum=max(curr, sum);
        }
        return sum;
    }
};
