class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxi=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                cnt++;
            }
            else // if we get 0 we make cnt=0
            {
                cnt=0;
            }
            maxi=max(maxi, cnt); // update maxi
        }
        return maxi;
    }
};