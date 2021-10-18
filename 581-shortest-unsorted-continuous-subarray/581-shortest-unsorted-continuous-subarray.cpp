class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sort;
        nums_sort=nums;
        sort(nums_sort.begin(), nums_sort.end());
        int start=nums.size(), end=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=nums_sort[i])
            {
                start=min(start, i);
                end=max(end,i);
            }
        }
        return end-start>=0?end-start+1:0;
    }
};