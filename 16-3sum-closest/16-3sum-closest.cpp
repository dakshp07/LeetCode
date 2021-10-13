class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size();
        int res=nums[0]+nums[1]+nums[length-1];
        sort(nums.begin(), nums.end());
        for(int i=0; i<length-2; i++)
        {
            int a=i+1;
            int b=length-1;
            while(a<b)
            {
                int sum=nums[a]+nums[b]+nums[i];
                if(sum>target)
                {
                    b--;
                }
                else
                {
                    a++;
                }
                if(abs(sum-target)<abs(res-target))
                {
                    res=sum;
                }
            }
        }
        return res;
    }
};