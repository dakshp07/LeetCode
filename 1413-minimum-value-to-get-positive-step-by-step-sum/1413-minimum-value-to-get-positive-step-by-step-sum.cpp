class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum=INT_MAX;
        int prefix_sum=0;
        int res=0;
        for(int i=0; i<nums.size(); i++)
        {
            prefix_sum+=nums[i];
            min_sum=min(min_sum, prefix_sum);
        }
        if(min_sum<0)
        {
            res=1-min_sum;
        }
        else
        {
            res=1;
        }
        return res;
    }
};