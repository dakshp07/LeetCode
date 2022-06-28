class Solution {
public:
    int minDeletions(string s) {
        // lets first store the freq of all chars in s
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]-'a']++;
        }
        // sort the freq, since we dont see chars we only need freq
        sort(freq.begin(), freq.end(), greater<int>());
        // there will be at max freq of s.length (ie all chars in s are same)
        int max_freq=s.length();
        // now for the freq of other chars we need it to be less than max freq
        int del=0;
        for(int i=0; i<26; i++)
        {
            // since we can just delete chars
            max_freq=min(max_freq, freq[i]);
            // deletions will be diff b/w frequencies
            del+=freq[i]-max_freq;
            // now noother char can have same freq as max_freq
            if(max_freq>0)
            {
                max_freq--;
            }
        }
        return del;
    }
};