class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length=nums.size();
        int res=0;
        for(int i=0; i<length-1; i++)
        {
            if(nums[i]<0 && nums[i+1]<0)
            {
                res=max(((nums[length-1]-1)*(nums[length-2]-1)),((nums[i]-1)*(nums[i+1]-1))); 
            }
            else
            {
                res=(nums[length-1]-1)*(nums[length-2]-1);
            }
        }
        return res;
    }
};