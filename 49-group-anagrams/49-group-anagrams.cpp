class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++)
        {
            string temp=strs[i];
            sort(strs[i].begin(), strs[i].end());
            umap[strs[i]].push_back(temp); 
        }
        for(auto x:umap)
        {
            vector<string> temp=x.second;
            ans.push_back(temp);
        }
        return ans;
    }
};