class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // so one way is to store the freq of p's letter
        // and then run a sliding window approach to check if s has p
        
        // base case
        if(s.size() < p.size()) return {};
        vector<int> freq(26, 0);
        for(int i=0; i<p.size(); i++)
        {
            freq[p[i]-'a']++;
        }
        // now we create another freq map
        // and run a window of size same as p
        vector<int> freq_s(26, 0);
        // first window
        int k=p.size();
        for(int i=0; i<k; i++)
        {
            freq_s[s[i]-'a']++;
        }
        vector<int> ans;
        if(freq_s==freq) ans.push_back(0);
        // now we start with the window
        // we remoce the left most ele freq and add freq of right most
        for(int j=k; j<s.size(); j++)
        {
            // remove freq of leftmost
            freq_s[s[j-k]-'a']--;
            // add freq of rightmost
            freq_s[s[j]-'a']++;
            // we add the index if the maps match
            if(freq_s==freq) ans.push_back(j-k+1);
        }
        return ans;
    }
};