class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        // initialize as 1 because at begining of array everything is max, min since we didnt saw any other ele
        int up=1, down=1;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]<nums[i+1]) // uphill
            {
                up=down+1;
            }
            else if(nums[i]>nums[i+1]) // downhill
            {
                down=up+1;
            }
        }
        return max(up, down);
    }
};