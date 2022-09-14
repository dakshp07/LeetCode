class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // we can create a map
        // and all the character mapping from s to t in it
        // for every char we check if that specific char has the same mapping
        unordered_map<char, char> mp;
        // one set to see the assigned values
        unordered_set<char> st;
        for(int i=0; i<s.size(); i++)
        {
            // now we see if s[i] is already in map
            // if its there we see if its corresponding char ie t[i] is not its mapping
            // which means s[i] is already mapped to someone which is not s[i]
            // if thats the case we return false
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i])
            {
                return false;
            }
            // the other case if s[i] is not in map but its corresponding char t[i] is in set
            // which means t[i] is already mapped to someone
            // then too we return false
            if(mp.find(s[i])==mp.end() && st.find(t[i])!=st.end())
            {
                return false;
            }
            // in other cases we map the chars and add t[i] to set
            mp[s[i]]=t[i];
            st.insert(t[i]);
        }
        return true; // if after all iterations we dont violate we return true
    }
};