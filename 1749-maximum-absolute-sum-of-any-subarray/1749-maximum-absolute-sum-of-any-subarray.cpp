class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // so at any index ind, i can either include this ele in my existing subarray
        // or i can start off a new subarray from here on
        // which essentially is kadane algo
        // so our max absolute sum will be the max sum or abs(min sum)
        int max_sum=INT_MIN;
        int min_sum=INT_MAX;
        int curr_max=0;
        int curr_min=0;
        for(int i=0; i<nums.size(); i++)
        {
            curr_max+=nums[i];
            curr_min+=nums[i];
            // now we update the value of max_sum and min_sum
            max_sum=max(curr_max, max_sum);
            min_sum=min(curr_min, min_sum);
            // we keep both 0, if they go out of bound
            // ie curr_min>0 and curr_max<0, as in this 0 is best ie an empty subarray
            if(curr_min>0) curr_min=0;
            if(curr_max<0) curr_max=0;
        }
        return max(max_sum, abs(min_sum));
    }
};