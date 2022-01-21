class Solution {
public:
    bool static comperator(pair<int, int> m, pair<int, int> n) {
        if(m.second==n.second)
        {
            return n.first<m.first;
        }
        return n.second>m.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto k:mp)
        {
            v.push_back(make_pair(k.first, k.second));
        }
        sort(v.begin(), v.end(), comperator);
        vector<int> res;
        for(int i=0; i<v.size(); i++)
        {
            while(v[i].second!=0)
            {
                res.push_back(v[i].first);
                v[i].second--;
            }
        }
        return res;
    }
};