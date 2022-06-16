class Solution {
public:
    string expandFromMiddle(string s, int left, int right)
    {
        while(left>=0 && right<s.length())
        {
            if(s[left]!=s[right]) break;
            else
            {
                left--; // increment, decrement right and left if they are same
                right++;
            }
        }
        return s.substr(left+1, right-left-1); // return the substring from boundries
    }
    
    void bestAns(string& ans, string& candidate, int& ansLen) { // to pick the best ans
        if(candidate.length() > ansLen) {
            ans = candidate;
            ansLen = candidate.length();
        }
    }
    
    string longestPalindrome(string s) {
        // one property of plaindrome is that you can start from middle
        // so we will create a helper to start from middle
        // and then cover two cases:
        // 1. racecar: a middle ele with no match
        // 2. abba: a middle char with match
        string ans="";
        int ansLen=0;
        for(int i=0; i<s.length(); i++)
        {
            string odd=expandFromMiddle(s, i, i); // for case "racecar"
            bestAns(ans, odd, ansLen); // check the best ans
            string even=expandFromMiddle(s, i-1, i); // for case "abba"
            bestAns(ans, even, ansLen); // check for the best when even comes in
            
        }
        return ans; // return the substring
    }
};