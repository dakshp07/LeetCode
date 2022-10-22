class Solution {
public:
    bool isAnagram(string s, string t) {
        // one way could be to sort both s,t and see if they are equal
        // tc: O(nlogn) + O(mlogm) where n,m are lengths of s,t strings sc: O(1)
        // other way is to check using freq map
        // tc: O(n) sc: O(26) which is constant
        if(s.length()!=t.length()) return false;
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0; i<t.length(); i++)
        {
            if(freq[t[i]-'a']==0) return false;
            freq[t[i]-'a']--;
        }
        return true;
    }
};