class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        // lets cal sum of all ele
        int sum=accumulate(nums.begin(), nums.end(), 0);
        // now right sum var will contain sum of all ele on right of ith
        // and left sum=sum-right_sum-arr[i]
        int right_sum=0;
        for(int i=0; i<n; i++)
        {
            if(i==0) right_sum=0;
            else right_sum+=nums[i-1];
            int left_sum=sum-right_sum-nums[i];
            if(left_sum==right_sum)
            {
                return i;
            }
        }
        return -1;
    }
};