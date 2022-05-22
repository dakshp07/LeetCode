class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane laga do
        int curr=nums[0];
        int sum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            // yaa toh curr+nums[i] ko lenge yaa phir sirf nums[i] ko
            // max lenge
            curr=max(curr+nums[i], nums[i]);
            // sum main bhi curr, sum ka max lenge
            sum=max(sum, curr);
        }
        return sum;
    }
};