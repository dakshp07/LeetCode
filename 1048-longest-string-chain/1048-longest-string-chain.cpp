class Solution {
public:
    static bool cmpr(string a, string b)
    {
        return a.size()<b.size();
    }
    bool compare(string &s, string &t)
    {
        // we consider s is bcda and t will be bcd
        if(s.size()!=t.size()+1) return false; // since the diff should be of just one char
        // we see if the pointers of string s, t reach the end of their respective strings simultaneously
        int pt1=0, pt2=0;
        while(pt1<s.size())
        {
            if(s[pt1]==t[pt2])
            {
                pt1++;
                pt2++;
            }
            // if they dont match we just move pt1
            else
            {
                pt1++;
            }
        }
        // if both reach end we return true
        if(pt1==s.size() && pt2==t.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        // this question is very much similar to lis
        // here in this question instead of finding lis we just need to see the max length of subsequence where the diff b/w two strings is just one character
        
        // here the question says sequence and not subsequence so we can sort the array on basis of length of words so that the subsets is handeled
        sort(words.begin(), words.end(), cmpr);
        int n=words.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(compare(words[i], words[prev]) && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }
        }
        int ans=-1;
        for(int i=0; i<n; i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
            }
        }
        return ans;
    }
};