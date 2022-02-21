class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // joh element n/2 se zyaada baari aaya hoga woh sort karte time ek taraf aajayega
        // 22223 sort kiya hua hain toh 2 aagaya n/2 pos pe
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};