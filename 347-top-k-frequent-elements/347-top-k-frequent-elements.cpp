class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // lets use a heap and map
        // map will store a num, its freq and then we pass that map to our heap
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        // stre freq
        for(auto &num: nums)
        {
            mp[num]++;
        }
        // pass the freq of each num in heap
        for(auto &i: mp)
        {
            // we make pair as (freq, num) so that heap will order acc to freq
            pq.push(make_pair(i.second, i.first));
        }
        // now our heap has ans, we need to extract only top k ele
        vector<int> res;
        while(k!=0)
        {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
