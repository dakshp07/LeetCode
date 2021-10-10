class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length=nums.size();
        int left=0;
        int right=length-1;
        int curr=0;
        while(curr<=right && left<right)
        {
            if(nums[curr]==0)
            {
                swap(nums[left], nums[curr]);
                left++;
                curr++;
            }
            else if(nums[curr]==2)
            {
                swap(nums[right], nums[curr]);
                right--;
            }
            else
            {
                curr++;
            }
        }
    }
};