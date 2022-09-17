class Solution {
public:
    int longestPalindrome(string s) {
        // we need to see the longest palindrome that we can build from the given chars
        vector<int> freq(128, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]]++;
        }
        // we check the chars that have even freq as we can take them
        // for the non even ones we need to see if our current res is even or not
        // if its even we take one char from the non even ones
        int ans=0;
        for(int i=0; i<128; i++)
        {
            // this expression will make sure that we pick even chars from freq
            ans+=freq[i]/2*2;
            // if the chars are odd then we pick just one from them
            if(ans%2==0 && freq[i]%2==1)
            {
                ans++;
            }
        }
        return ans;
    }
};
