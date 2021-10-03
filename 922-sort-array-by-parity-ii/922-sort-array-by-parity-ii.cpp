class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int length=nums.size();
        int i=0;
        int j=1;
        while(i<length && j<length)
        {
            while(i<length && nums[i]%2==0)
            {
                i+=2;
            }
            while(j<length && nums[j]%2==1)
            {
                j+=2;
            }
            if(i<length && j<length)
            {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};