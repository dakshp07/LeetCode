class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid=nums.size()/2;
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            int diff=abs(nums[mid]-nums[i]);
            ans+=diff;
        }
        return ans;
    }
};