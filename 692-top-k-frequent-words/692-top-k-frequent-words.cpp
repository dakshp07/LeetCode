class Solution {
public:
    struct cmpr{
		bool operator()(pair<int,string> a, pair<int,string> b) const{
			if(a.first==b.first) return a.second<b.second;
			return a.first>b.first;
		}
	};
    vector<string> topKFrequent(vector<string>& words, int k) {
        // there are two ways to solve problem:
        // 1. use map and then use a cmpr on vec. tc: O(logn)+O(nlogn)+O(logn)
        // 2. use map and then use a cmpr on heap. tc: O(logn)+O(logn)+O(1) 
        // so we use a map <string,freq> and a heap of pairs <freq,words>
        // heap will help in keeping track of most freq ele
        unordered_map<string,int> mp;
        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }
        // we use comp on the heap to sort them acc to lexi if freq is same
        priority_queue<pair<int,string>, vector<pair<int, string>>, cmpr> pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // reverse the vec
        reverse(ans.begin(), ans.end());
        return ans;
    }
};