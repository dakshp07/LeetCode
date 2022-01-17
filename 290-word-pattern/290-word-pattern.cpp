class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> w2p;
        unordered_map<string, int> p2w;
        istringstream in(s); 
        string word;
        int i = 0, n = pattern.size();
        for(word; in>>word; i++)
        {
            if(i==n || w2p[pattern[i]]!=p2w[word])
            {
                return false;
            }
            w2p[pattern[i]]=p2w[word]=i+1;
        }
        return i==n;
    }
};