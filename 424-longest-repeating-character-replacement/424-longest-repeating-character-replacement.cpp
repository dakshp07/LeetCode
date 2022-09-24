class Solution {
public:
    int characterReplacement(string s, int k) {
        // we use a sliding window approach
        // we keep a start,end of the window
        // and update the window of map everytime we see a new char
        // and ultimately stop when k=0
        int start=0;
        int max_len=0;
        vector<int> freq(26, 0);
        int max_count=0;
        for(int end=0; end<s.size(); end++)
        {
            // we add the right side to our freq
            freq[s[end]-'A']++;
            // now we keep track of the max same char we have seen till now
            max_count=max(max_count, freq[s[end]-'A']);
            // now we need to see if the distinct char count < k
            // distinct ele=window length-same char count+1
            // distinct ele=end-start-max_count+1 (1 is added since we will consider the char at end position)
            // if it not then we update our window
            while(end-start-max_count+1>k)
            {
                // we pop from start and add new char of new window from end
                freq[s[start]-'A']--;
                // and update the start
                start++;
            }
            // update the max length
            max_len=max(end-start+1, max_len);
        }
        return max_len;
    }
};