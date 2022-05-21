class Solution {
public:
    int findMin(vector<int>& nums) {
        // simple sol but n*logn
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};