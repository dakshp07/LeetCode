class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we can use a map to store freq, nums and then sort it using comperator
        // tc: O(n logn) and we need to do it in much better tc
        // so we use heap, we store freq,nums in heap and then return the ans
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        // we push freq,nums in our pq
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(k!=0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
