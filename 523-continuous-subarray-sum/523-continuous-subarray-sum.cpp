class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // sum, rem ka logic use hoga
        // pepcoding ka video tha
        // agar s1/k gives rem x and s2/k gives rem x then the ele b/w s1 and s2 are perfectly                  divisible by k;
        // rem ka freq dekhte jaao or hashmap main daalo, jaise hi uss rem ka value 2 hogaya return
        unordered_map<int, int> mp;
        int sum=0;
        int curr=0; // current ptr
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)!=mp.end())
            {
                return true;
            }
            mp[curr]++; // agar first time aaya toh phele curr waala ka +1
            curr=rem;
        }
        return false;
    }
};