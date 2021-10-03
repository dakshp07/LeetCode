class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_index = 0;
        for(int i = 1; i<nums.size();i++){
            if(nums[i]>nums[max_index]){
                max_index = i;
            }
        }
        for(int i = 0; i<nums.size();i++){
            if(nums[i]*2 > nums[max_index] && i!=max_index){
            return -1;
            }
        }
        return max_index;
    }
};