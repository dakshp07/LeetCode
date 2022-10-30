class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // we can use map to put num,freq in it
        // but that violates const space
        // we can also sort but that violates linear time complexity
        // so we use XOR
        // all the same numbers XOR is 0
        // at the end we will only have the number which comes once
        for(int i=1; i<nums.size(); i++)
        {
            nums[i]=nums[i]^nums[i-1];
        }
        return nums[nums.size()-1]; // since rest all places are filled with other numbers
    }
};