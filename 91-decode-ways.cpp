class Solution {
public:
    int numDecodings(string s) {
        // so this is similar to word break problem (https://leetcode.com/problems/word-break/description/)
        // we make cuts and solve the rhs and lhs
        // we use recursion and then optimise it further down
        /*
        recursion:
        int func(int ind)
        {
            // base case:
            // 1. if s[ind] is 0
            if(s[ind]=='0') return 0;
            // 2. if we cross the entire string
            if(ind==s.size()-1) return 1;
            
            // now we pick a number individually or we can make pairs with its other number
            if(s[ind]=='1' || (s[ind]=='2' && (s[ind+1]>=48 && s[ind+1]<=54)))
            {
                // >=48 means '0' and <=54 means '6' since we cant move ahead then 26 hence we return that condition
                // so now we take a number next
                // and then move pointer to ind+2 to consider rest cases
                // eg: 12134
                // we make a cut after 12 and move ahead for next number by taking ind+2
                    ind+1      ind+2
                // 1   2     |   1      34
                return func(ind+1)+func(ind+2);
            }
            // if any ind+2 is going out of bound we just take ind+1
            return func(ind+1);
        }

        memoization:
        vector<int> dp(s.size()+1, -1);
        int func(int ind)
        {
            if(dp[ind]!=-1) return dp[ind]
            // base case:
            // 1. if s[ind] is 0
            if(s[ind]=='0') return 0;
            // 2. if we cross the entire string
            if(ind==s.size()-1) return 1;
            
            // now we pick a number individually or we can make pairs with its other number
            if(s[ind]=='1' || (s[ind]=='2' && (s[ind+1]>=48 && s[ind+1]<=54)))
            {
                // >=48 means '0' and <=54 means '6' since we cant move ahead then 26 hence we return that condition
                // so now we take a number next
                // and then move pointer to ind+2 to consider rest cases
                // eg: 12134
                // we make a cut after 12 and move ahead for next number by taking ind+2
                    ind+1      ind+2
                // 1   2     |   1      34
                return dp[ind]=func(ind+1)+func(ind+2);
            }
            // if any ind+2 is going out of bound we just take ind+1
            return dp[ind]=func(ind+1);
        }
        */
        // tabulation:
        vector<int> dp(s.size()+1);
        // 1. if s[ind] is 0: will handle in for loop
        // 2. if we cross the entire string
        dp[s.size()]=1;
        for(int ind=s.size()-1; ind>=0; ind--)
        {
            // base case #1
            if(s[ind]=='0') dp[ind]=0;
            else if(int(s[ind]-'0')>2)dp[ind]+=dp[ind+1];
            else
            {
                dp[ind]+=dp[ind+1];
                if(ind+1<s.size() && int(s[ind]-'0')==1)dp[ind]+=dp[ind+2];
                if(ind+1<s.size() && int(s[ind]-'0')==2 && int(s[ind+1]-'0')<=6)dp[ind]+=dp[ind+2];
            }
        }
        return dp[0];
    }
};
