class Solution {
public:
    int findLHS(vector<int>& nums) {
        int length=nums.size();
        sort(nums.begin(), nums.end());
        int left=0, right=1, res=0;
        while(right<length)
        {
            int diff=nums[right]-nums[left];
            if(diff==1)
            {
                res=max(res, right-left+1);
            }
            if(diff<=1)
            {
                right++;
            }
            else
            {
                left++;
            }
        }
        return res;
    }
};