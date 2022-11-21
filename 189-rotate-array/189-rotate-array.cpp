class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reverse the whole array. Then reverse the first k elements. Finally reverse the remaining elements. (Do a dry run, it's very easy to understand)
        k = k%nums.size(); // If k>=n do k = k%n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};