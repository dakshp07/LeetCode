class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // map main prefix sum store karenge
        // humko woh sub array chaiye jiska sum is equal to x
        // uska length will be the ans
        int target=-x;
        for(int i=0; i<nums.size(); i++)
        {
            target+=nums[i];
        }
        if(target==0) return nums.size();
        unordered_map<int, int> mp;
        mp[0]=-1;
        int res=-1, sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end())
            {
                res=max(res, i-mp[sum-target]);
            }
            mp[sum]=i;
        }
        return res==-1 ? -1 : nums.size()-res;
    }
};