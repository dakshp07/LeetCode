int cmpr(pair<char,int> a, pair<char,int> b)
{
    return a.second>b.second;
}
    
class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++)
        {
            umap[s[i]]++;
        }
        vector<pair<char,int>> v(umap.begin(), umap.end()) ;
        
        sort(v.begin(), v.end(), cmpr);
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].second; j++)
            {
                res += v[i].first;
            }
        }
        return res;
    }
};