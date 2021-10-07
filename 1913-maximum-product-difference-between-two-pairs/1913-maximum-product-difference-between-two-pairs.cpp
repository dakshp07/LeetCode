class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length=nums.size();
        int max=0;
        for(int i=0; i<length; i++)
        {
            if(nums[i]<0 && nums[i+1]>0)
            {
                max=(nums[length-1]*nums[length-2])-(nums[i]*nums[i+1]);
            }
            else
            {
                max=(nums[length-1]*nums[length-2])-(nums[0]*nums[1]);
            }
        }
        return max;
    }
};