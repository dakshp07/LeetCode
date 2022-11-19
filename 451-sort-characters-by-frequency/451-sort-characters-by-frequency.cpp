class Solution {
public:
    string frequencySort(string s) {
        // this question is similar to Q-347 on LeetCode
        // so we do it in simialr fashion
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        string res="";
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char word=pq.top().second;
            pq.pop();
            while(freq!=0)
            {
                res+=word;
                freq--;
            }
        }
        return res;
    }
};