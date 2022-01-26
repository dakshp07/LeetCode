class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[curr]!=nums[i])
            {
                nums[++curr]=nums[i];
                // curr++;
            }
        }
        if(nums.size()==0)
        {
            return 0;
        }
        return curr+1;
    }
};