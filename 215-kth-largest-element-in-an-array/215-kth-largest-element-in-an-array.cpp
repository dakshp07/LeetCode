class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(i+1==k)
            {
                return nums[i]; 
            }
        }
        return 0;
    }
};