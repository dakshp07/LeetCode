class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length() || s2.length()==0) return false;
        if(s1.length()==0) return true;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(int i=0; i<s1.length(); i++)
        {   // first window
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i=s1.length(); i<s2.length(); i++)
        {
            if(freq1==freq2)
            {
                return true;
            }
            // sliding the window
            freq2[s2[i-s1.length()]-'a']--;
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)
        {
            return true;
        }
        return false;
    }
};