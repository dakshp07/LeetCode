class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length=nums.size();
        vector<int> res;
        for(int i=0; i<length-1; i++)
        {
            if(nums[i]==nums[i+1])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};