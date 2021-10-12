class Solution {
public:
    int findMin(vector<int>& nums) {
        int length=nums.size();
        int min=INT_MAX;
        for(int i=0; i<length; i++)
        {
            if(nums[i]<min)
            {
                min=nums[i];
            }
        }
        return min;
    }
};