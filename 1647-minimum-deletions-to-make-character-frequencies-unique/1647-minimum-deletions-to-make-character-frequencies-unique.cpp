class Solution {
public:
    int minDeletions(string s) {
        // maitain a threshold freq f whch will be the max freq of that string
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int f=freq[0];
        int ans=0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]>f)
            {
                if(f>0) ans+=(freq[i]-f);
                else ans+=freq[i];
            }
            f=min(f-1, freq[i]-1);
        }
        return ans;
    }
};