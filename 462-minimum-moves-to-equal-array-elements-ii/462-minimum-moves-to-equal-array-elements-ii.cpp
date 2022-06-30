class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // its always good to change the eles to ele present at median value of sorted
        sort(nums.begin(), nums.end());
        int median=nums[nums.size()/2];
        int moves=0;
        for(int i=0; i<nums.size(); i++)
        {
            moves+=abs(nums[i]-median);
        }
        return moves;
    }
};