class Solution {
public:
    static bool compare(pair<int,string> a,pair<int,string> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        map<string,int>::iterator it;
        vector<pair<int,string>>v1;
        for(it=mp.begin();it!=mp.end();it++){
            
            v1.push_back(make_pair(it->second,it->first));
        }
        sort(v1.begin(),v1.end(),compare);
        vector<string> ans;
        int cnt=0;
        for(int i=v1.size()-1;i>=0;i--){
            if(cnt==k){
                break;
            }cnt++;
            
            ans.push_back(v1[i].second);
        }
        return ans;
        
    }
};