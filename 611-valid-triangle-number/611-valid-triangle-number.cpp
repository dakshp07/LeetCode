class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            int left=0;
            int cons=i;
            int right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right]>nums[cons])
                {
                    count+=(right-left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return count;
    }
};