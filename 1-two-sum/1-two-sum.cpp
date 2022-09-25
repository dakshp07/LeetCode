class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute is to run two loops. tc: O(n^2) and sc: O(1)
        // one of the standard way is to sort and use a two pointer approach
        // and see if we get the ans 
        // tc: O(nlogn) and s : O(1)
        
        // but lets see if we can do it off in one traversal
        // we use a hash map to keep track of ele and their indices
        // mp<ele,index>
        // tc: O(n) and sc: O(n)
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            // if nums[i] and target-nums[i] are there in map then we add them to vector and break
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            // or else we add the nums[i] to our map
            mp[nums[i]]=i;
        }
        return ans;
    }
};