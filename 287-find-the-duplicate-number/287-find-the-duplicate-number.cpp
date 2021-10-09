class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length=nums.size();
        int res=0;
        for(int i=0; i<length-1; i++)
        {
            if(nums[i]==nums[i+1])
            {
                res=nums[i];
            }
        }
        return res;
    }
};