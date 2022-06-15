class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane lagao
        int curr_sum=nums[0], max_sum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            // yaa toh curr+nums[i] ko lenge yaa phir sirf nums[i] ko
            // max lenge
            curr_sum=max(curr_sum+nums[i], nums[i]);
            // sum main bhi curr, sum ka max lenge
            max_sum=max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
