class Solution {
public:
    bool solve(string w, string p)
    {
        unordered_map<char, char> wp, pw;
        for(int i=0; i<w.size(); i++)
        {
            // we look for word in word-pattern map
            if(wp.find(w[i])!=wp.end()) // means we have
            {
                // if the words char and pattern char are not equal we return false
                if(wp[w[i]]!=p[i]) return false;
            }
            // if we dont find then we add
            else wp[w[i]]=p[i];
        }
        // we do same again but from pattern to word
        for(int i=0; i<w.size(); i++)
        {
            // we look for pattern in pattern-word map
            if(pw.find(p[i])!=pw.end()) // means we have
            {
                // if the patterns char and the word char are not equal we return false
                if(pw[p[i]]!=w[i]) return false;
            }
            // if we dont find then we add
            else pw[p[i]]=w[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // bolta hu map banate 2
        // ek pattern se words ki mapping or ek words se pattern ke liye
        // we check if the mapping exsits from both the sides
        // if they match we know that the word is our ans
        vector<string> ans;
        for(auto it: words)
        {
            // we add word if solve returns true
            if(solve(it, pattern)) ans.push_back(it);
        }
        return ans;
    }
};