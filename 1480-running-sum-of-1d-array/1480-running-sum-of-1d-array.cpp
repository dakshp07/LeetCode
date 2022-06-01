class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int run_sum=0;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            run_sum+=nums[i];
            res.push_back(run_sum);
        }
        return res;
    }
};