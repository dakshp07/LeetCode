class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> char_count(26);
        for(int i=0; i<p.length(); i++)
        {
            char_count[p[i]-'a']++;
        }
        int left=0;
        int right=0;
        int count=p.length();
        vector<int> res;
        while(right<s.length())
        {
            if(char_count[s[right++]-'a']-->=1)
            {
                count--;
            }
            if(count==0)
            {
                res.push_back(left);
            }
            if(right-left==p.length() && char_count[s[left++]-'a']++>=0)
            {
                count++;
            }
        }
        return res;
    }
};