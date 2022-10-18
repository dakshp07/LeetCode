class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // one of the ways is to sort the array and then use two pointer approach
        // tc: O(nlogn) sc: O(1)
        // the other is to use a map
        // <ele,index> if we see any entry in map which is target-ele 
        // then we add mp[target-ele] and i to ans
        // tc: O(n) and sc: O(n)
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};