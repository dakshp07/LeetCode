class Solution {
public:
    string customSortString(string orders, string s) {
        vector<int> freq(26);
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        string ans="";
        for(int i=0; i<orders.length(); i++)
        {
            while(freq[orders[i]-'a']>0)
            {
                ans+=orders[i];
                freq[orders[i]-'a']--;
            }
        }
        for(int i=0; i<26; i++)
        {
            while(freq[i]>0)
            {
                ans+=(i+'a');
                freq[i]--;
            }
        }
        return ans;
    }
};