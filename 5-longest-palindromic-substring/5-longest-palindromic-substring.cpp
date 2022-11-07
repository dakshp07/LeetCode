class Solution {
public:
    string expand(string s, int left, int right)
    {
        if(left>right) return 0;
        while(left>=0 && s[left]==s[right])
        {
            left--;
            right++;
        }
        return s.substr(left+1, right-(left+1));
    }
    string longestPalindrome(string s) {
        // brute force way is to use two for loops and generate all substrings
        // store those substrings and find the longest one
        // tc: O(n^2) for generating all subsets and another O(n), so total tc: O(n^3)
        // which is very big
        
        // we use the concept of plaindrome where we expand from the center of a string
        // and look for the substring which are valid palindromes
        if(s.size()<1) return "";
        string ans="";
        for(int i=0; i<s.size(); i++)
        {
            // now there are two types of palindromes
            // 1.even length (eg: bb, abba)
            // 2.odd length(eg: bab, racecar)
            // so we try both possibilities
            // and choose the one which gives max len ans
            string odd=expand(s, i, i);
            string even=expand(s, i, i+1);
            string max=odd.size()>even.size()?odd:even;
            ans=ans.size()<max.size()?max:ans;
        }
        return ans;
    }
};