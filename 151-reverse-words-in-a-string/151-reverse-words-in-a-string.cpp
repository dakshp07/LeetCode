class Solution {
public:
    string reverseWords(string s) {
        // the first task will be take our individual words and reverse them individually
        // we use a string stream to taeke the words from white spaces
        stringstream st(s);
        string res="";
        string word;
        vector<string> alpha;
        while(st>>word)
        {
            alpha.push_back(word);
        }
        reverse(alpha.begin(), alpha.end());
        for(int i=0; i<alpha.size(); i++)
        {
            res+=alpha[i];
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};