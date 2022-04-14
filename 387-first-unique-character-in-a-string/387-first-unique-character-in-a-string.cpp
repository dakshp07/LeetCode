class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        // freq store karlo
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        // iterate on string chars and see if we have any char whose freq is 1
        for(int i=0; i<s.length(); i++)
        {
            if(freq[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};