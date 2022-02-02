class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0);
        for(int i=0; i<p.length(); i++)
        {
            freq[p[i]-'a']++;
        }
        vector<int> res;
        int left=0, right=0, count=p.length();
        while(right<s.length())
        {
            if(freq[s[right++]-'a']-->=1)
            {
                // freq[s[right]-'a']--; The commented lines give TLE
                // right++;
                count--;
            }
            if(count==0)
            {
                res.push_back(left);
            }
            if(right-left==p.length() && freq[s[left++]-'a']++>=0)
            {
                // freq[s[left]-'a']++; The commented lines give TLE
                // left++;
                count++;
            }
        }
        return res;
    }
};