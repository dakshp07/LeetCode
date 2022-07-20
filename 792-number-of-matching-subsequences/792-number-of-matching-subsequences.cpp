class Solution {
public:
    bool isSubSeq(string s, string t)
    {
        // start traversing
        int i=0, j=0;
        while(i<s.length() && j<t.length())
        {
            // if we see a match b/w both the chars
            if(s[i]==t[j])
            {
                // we increment t pointer
                j++;
            }
            // i should be incremented in all other caes
            i++;
        }
        // at the end if we traverse the entire word string
        // ie if j==t.length() we return true
        if(j==t.length())
        {
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        // so for every word in words we will check if its a subsequence
        int cnt=0;
        // map will store frequency
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }
        for(auto it: mp)
        {
            if(isSubSeq(s, it.first))
            {
                cnt+=it.second;
            }
        }
        return cnt;
    }
};