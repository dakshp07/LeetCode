class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // so we need to see if for any prefix in s we are able to find it in word dict
        /*
        eg 1: s = "leetcode", wordDict = ["leet","code"]
        - if i make a cut after l in s ie l | eetcode, we have to see if both the words on rhs, lhs of cut are a part of word dict or not
        - if this is not satisfying, we go on to make more cuts till we get a perfect match or till we have seen all permutations and combinations

        eg 2: from ith character we will check if that substring occurs in given list of words
        - if it appears we will call recursion from the character next to it
    
        s = "applepenapple", wordDict = ["apple","pen"]
    
        - here apple is present in wordDict. so call recursion on remaining string "penapple" 
        - if it returns true then return true else keep matching next chars and try for next possibilities
        - if i reaches end of string then return true
        */
        // so the explanation makes it a recursion problem as we need to explore all the possible methods
        /*
        recursion: tc: O(exponential) and sc: O(s.size())
        int func(int ind)
        {
            // base case:
            // 1. now if i reach end of string, we return true as we computed all chars and never returned false
            if(i==s.size()) return 1;
            
            // now we check all potential combinations with j
            string temp="";
            for(int j=i; j<s.size(); j++)
            {
                temp+=s[j];
                if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end())
                {
                    // if temp appears in wordDict, we now we make another cut from here
                    if(func(j+1)) return 1;
                }
            }
            return 0;
        }

        memoization:
        vector<int> dp(s.size()+1, -1);
        int func(int ind)
        {
            // base case:
            // 1. now if i reach end of string, we return true as we computed all chars and never returned false
            if(i==s.size()) return 1;
            if(dp[ind]!=-1) return true;
            // now we check all potential combinations with j
            string temp="";
            for(int j=i; j<s.size(); j++)
            {
                temp+=s[j];
                if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end())
                {
                    // if temp appears in wordDict, we now we make another cut from here
                    if(func(j+1)) return dp[ind]=1;
                }
            }
            return dp[ind]=0;
        }
        */
        // tabulation: O(n) and sc: O(n+1) where n is s.size()
        int n=s.size();
        vector<int> dp(n+1, 0);
        // base case:
        // when we reach end we return true
        // so dp[n] ie last index of dp it will be true
        dp[n]=1;
        // we start ind from end as in our recursion ind was from 0th index
        for(int ind=n-1; ind>=0; ind--)
        {
            string temp="";
            for(int j=ind; j<n; j++)
            {
                temp+=s[j];
                if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end())
                {
                    // if temp appears in wordDict, we now we make another cut from here
                    if(dp[j+1]) dp[ind]=1;
                }
            }
            // dp[ind]=0; we remove this from tabulation because our dp is already prefilled with 0s
        }
        return dp[0];
    }
};
