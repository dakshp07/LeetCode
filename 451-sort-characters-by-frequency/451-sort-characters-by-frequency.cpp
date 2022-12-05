class Solution {
public:
    string frequencySort(string s) {
        // this question is similar to Q-347 on LeetCode
        // so we do it in simialr fashion
        unordered_map<char, int> mp;
        // store freq in char map
        for(auto it: s)
        {
            mp[it]++;
        }
        // pass char map in max heap as int, char pair
        priority_queue<pair<int, char>> pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        // now we create the string
        string res="";
        while(!pq.empty())
        {
            int num=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(num!=0)
            {
                res+=ch;
                num--;
            }
        }
        return res;
    }
};