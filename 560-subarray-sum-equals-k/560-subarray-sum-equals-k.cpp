class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        int count=0, sum=0;
        mp[0]=1; // storing the count of times when i saw a sum
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};