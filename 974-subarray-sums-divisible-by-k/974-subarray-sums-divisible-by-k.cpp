class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // the logic here is that if any subarray with sum s1 gives an reminder of x after dividing with k
        // and theres another subarray with sum s2 gives an reminder of x after dividing k
        // the one of the subarray which will be divisible by k lies b/w the subarray with sums s1, s2
        // s=k*q+x and s2=k*p+x
        // sum of ele in b/w=s1-s2 => (k*q+x)-(k*p+x) => k(q-p) which is divisible by k
        unordered_map<int, int> mp; // stores freq of rem (rem, freq)
        mp[0]=1; // as we start with sum=0 so remainder will be 0
        int sum=0, rem=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
            {
                rem+=k; // if reminder is -5 we add k to make it positive
            }
            // we check if we've seen this reminder
            if(mp.find(rem)!=mp.end())
            {
                // we add the freq of that rem in ans
                ans+=mp[rem];
                // we also make the freq of rem +1
                mp[rem]++;
            }
            // if we have not seen that rem we add it in map
            else
            {
                mp[rem]=1;
            }
        }
        return ans;
    }
};