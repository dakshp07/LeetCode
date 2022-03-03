class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2)
        {
            return 0;
        }
        int diff=nums[1]-nums[0];
        int cnt=0, in=0;
        for(int i=1; i<n-1; i++)
        {
            if(diff==nums[i+1]-nums[i])
            {
                in++;
            }
            else
            {
                diff=nums[i+1]-nums[i];
                in=0;
            }
            cnt+=in;
        }
        return cnt;
    }
};