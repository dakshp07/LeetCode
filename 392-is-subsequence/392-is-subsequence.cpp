class Solution {
public:
    bool isSubsequence(string s, string t) {
        // we run our pointer through the two strings
        int i=0, j=0;
        // we traverse both strings
        while(i<s.length() && j<t.length())
        {
            // if the char match we move both
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            // we just move j
            else
            {
                j++;
            }
        }
        // we see if i reached the end of s or not
        // if it didnt means we ran out of t before s ended hence t isnt a subseq of s
        return i==s.length();
    }
};