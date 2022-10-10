class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // so we need to check that the absolute difference should be as small as possible
        // we use a for loop and two pointers and apply binary search on it
        // intialize sum as nums[0]+nums[1]+nums[nums.size()-1];
        int res=nums[0]+nums[1]+nums[nums.size()-1];
        sort(nums.begin(), nums.end()); // sort the array
        for(int i=0; i<nums.size()-2; i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            // now we do binary search and look for the the sum
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(target>sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
                // now we check if the abs diff of sum is less than the prev values
                if(abs(res-target)>abs(sum-target))
                {
                    res=sum; // update res
                }
            }
        }
        return res;
    }
};