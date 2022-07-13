class Solution {
public:
    // expand function
    string expand(string s, int left, int right)
    {
        if(left>right) return 0;
        // move left and right acc to conditions
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            // update left and right
            left--;
            right++;
        }
        // return the len
        return s.substr(left + 1, right - (left + 1));
    }
    string longestPalindrome(string s) {
        // brute force way is to use two for loops and generate all substrings
        // store those substrings and find the longest one
        // tc: O(n^2) for generating all subsets and another O(n), so total tc: O(n^3)
        // which is very big
        
        // we use the concept of plaindrome where we expand from the center of a string
        // and look for the substring which are valid palindromes
        if(s.size()<1) return "";
        int start=0, end=0; // start and end pointer
        string ans;
        for(int i=0; i<s.size(); i++)
        {
            // we can have two possibilities here
            // one is odd len string, other even string
            string odd=expand(s, i, i); // odd has one center
            string even=expand(s, i, i+1); // even has two centers
            string max = odd.size() > even.size() ? odd : even; // take the max len string
            ans = max.length() > ans.length() ? max : ans; // get the ans as max
        }
        return ans;
    }
};