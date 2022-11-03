class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force would be to find all subarrays using recursion
        // and then iterate over them to see how many have sum==k
        
        // we can use a map to optimise it
        // in map we store the number of times we saw a sum
        // so lets say if we find a subarray with sum x
        // and another subarray of sum x+k
        // then the subarray lying in b/w the these two will have sum of k
        // so we store how many times we saw a sum and look for how many times we say sum-k
        map<int, int> mp;
        mp[0]=1; // we saw sum of 0 just once
        int cnt=0, sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            // since we already have a subarray with sum as sum
            // we look for sum-k in our map
            // if it exists we add the corresponding map value in cnt
            if(mp.find(sum-k)!=mp.end())
            {
                cnt+=mp[sum-k];
            }
            // we also add this sum to our map
            mp[sum]++;
        }
        return cnt;
    }
};