class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res=0;
        int anc=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i-1]>=nums[i])
            {
                anc=i;
            }
            res=max(res, i-anc+1);
        }
        return res;
    }
};