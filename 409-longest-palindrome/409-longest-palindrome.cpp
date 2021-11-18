class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        vector<int> freq(128, 0);
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]]++;
        }
        for(int i=0; i<freq.size(); i++)
        {
            res+=(freq[i]/2)*2;
            if(res%2==0 && freq[i]%2==1)
            {
                res+=1;
            }
        }
        return res;
    }
};