class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // we use concept of sliding window
        int sum=0;
        int left=0;
        int right=0;
        int ans=INT_MAX;
        while(right<nums.size())
        {
            sum+=nums[right];
            right++;
            while(sum>=target)
            {
                sum-=nums[left];
                left++;
                ans=min(ans, right-left+1);
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};
