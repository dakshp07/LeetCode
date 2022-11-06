class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // so anagrams when sorted are same
        // so if we have two words we can sort them up and see if they are really anagrams or not
        unordered_map<string, vector<string>> mp;
        // mp will have {sorted words, {all words that are anagrams}}
        for(int i=0; i<strs.size(); i++)
        {
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
            // so my map will get {sorted, {anagrams}}
            // and if we came across any anagram which already has its sorted word as an entry
            // then map will push it into that specific place
        }
        vector<vector<string>> res;
        for(auto it: mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};