class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++)
        {
            if(freq[t[i]-'a']==0)
                freq[t[i]-'a']++;
            else
                freq[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(freq[i]==1)
            {
                return i+'a';
            }
        }
        return ' ';
    }
};