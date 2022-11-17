class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        // constraints are small
        // so we go through brute way and check for all subarrays
        int curr_gcd=0, ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            curr_gcd=nums[i];
            for(int j=i; j<nums.size(); j++)
            {
                if(nums[j]%k!=0) break; // as we cant include this in our subarray
                curr_gcd=__gcd(curr_gcd, nums[j]); // else we include this ele and see the new gcd
                // if new gcd is equal to k we increment ans
                if(curr_gcd==k) ans++;
            }
        }
        return ans;
    }
};