class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // so we use a map and everytime for all ele in pattern
        // we see if its in map or not
        // if its there we check if its corresponding val is euqals to s
        // if it isnt we return false, else we return true
        
        // but but it says bijection, so we can use two maps. to see if all are bijected
        // or i can use one map and one set, set will store all chars of s
        // if a char of s is not in map but its in set means its there in map ie. different pattern with same word which is false
        vector<string> v;
        string word;
        unordered_map<char, string> mp;
        unordered_set<string> st;
        stringstream iss(s);
        while(iss>>word)
        {
            v.push_back(word);
        }
        if(v.size()!=pattern.size()) return false;
        for(int i=0; i<pattern.size(); i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=v[i]) return false;
                else continue;
            }
            else
            {
                if(st.count(v[i])>0) return false;
                mp[pattern[i]]=v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};