class Solution {
public:
    bool isAnagram(string s, string t) {
        // one of the ways is to sort the strings and check if they are same
        // tc: O(nlogn) 
        // we can also use kmp algo to check if the strings are anagrams
        // tc: O(n)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};