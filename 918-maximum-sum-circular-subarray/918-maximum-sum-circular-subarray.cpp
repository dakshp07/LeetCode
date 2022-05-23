class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int t=0, mxs=nums[0], currmx=0, mis=nums[0], currmi=0;
        for(int i=0; i<nums.size(); i++)
        {
            currmx=max(currmx+nums[i], nums[i]);
            mxs=max(mxs, currmx);
            currmi=min(currmi+nums[i], nums[i]);
            mis=min(mis, currmi);
            t+=nums[i];
        }
        return mxs>0 ? max(mxs, t-mis) : mxs; 
    }
};