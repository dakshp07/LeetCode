class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int i=0; i<nums.size(); i++) {
            freq_map[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size() + 1); 
        for (auto& kv : freq_map) {
            int num = kv.first;
            int freq = kv.second;
            buckets[freq].push_back(num);
        }
        vector<int> res;
        for (int i = nums.size(); i >= 1 && res.size() < k; i--) {
            if (!buckets[i].size())
                continue;
            for (int num : buckets[i]) {
                if (res.size() == k) break;
                res.push_back(num);
            }
        }
        return res;
    }
};