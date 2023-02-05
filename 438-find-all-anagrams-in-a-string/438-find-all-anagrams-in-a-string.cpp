class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // again this is to similar to Q567
        // we use a freq array and check the combination using sliding window
        // base case
        if(s.size() < p.size()) return {};
        vector<int> mp1(26, 0), mp2(26, 0);
        // populate the maps for first window
        for(int i=0; i<p.size(); i++)
        {
            mp1[s[i]-'a']++;
            mp2[p[i]-'a']++;
        }
        vector<int> ans;
        if(mp1==mp2)
        {
            ans.push_back(0);
        }
        for(int i=p.size(); i<s.size(); i++)
        {
            mp1[s[i-p.size()]-'a']--;
            mp1[s[i]-'a']++;
            if(mp1==mp2)
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};
