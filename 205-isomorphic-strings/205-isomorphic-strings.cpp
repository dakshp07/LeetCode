class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> char_map;
        unordered_map<char, bool> true_map;
        for(int i=0; i<s.length(); i++)
        {
            if(char_map.find(s[i])!=char_map.end())
            {
                if(char_map[s[i]]!=t[i])
                {
                    return false;
                }
            }
            else
            {
                if(true_map.find(t[i])!=true_map.end())
                {
                    return false;
                }
                else
                {
                    char_map[s[i]]=t[i];
                    true_map[t[i]]=true;
                }
            }
        }
        return true;
    }
};