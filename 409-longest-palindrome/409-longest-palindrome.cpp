class Solution {
public:
    int longestPalindrome(string s) {
        // so in order to make a palindrome, we need chars in even numbers
        // and one char can stay in middle
        // eg: abcdcba, here a,b,c are in even numbers and d is just one
        // so we same concept here
        vector<int> freq(128, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]]++;
        }
        int len=0;
        for(int i=0; i<128; i++)
        {
            // this expression will make sure that we pick even chars from freq
            len+=freq[i]/2*2;
            // if the chars are odd then we pick just one from them
            if(len%2==0 && freq[i]%2==1)
            {
                // we take just one
                len+=1;
            }
        }
        return len;
    }
};
