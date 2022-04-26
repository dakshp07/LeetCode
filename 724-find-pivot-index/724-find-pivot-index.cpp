class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totsum=0;
        for(int i=0; i<nums.size(); i++)
        {
            totsum+=nums[i];
        }
        int leftsum=0, rightsum=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i==0)
            {
                leftsum=0;
                rightsum=totsum-leftsum-nums[i];
            }
            else
            {
                leftsum+=nums[i-1];
                rightsum=totsum-leftsum-nums[i];
            }
            if(leftsum==rightsum) return i;
        }
        return -1;
    }
};