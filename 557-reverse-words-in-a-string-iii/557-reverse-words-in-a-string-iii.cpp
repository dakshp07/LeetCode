class Solution {
public:
    string reverseWords(string s) {
        // we will use string stream to store the words separately
        stringstream st(s);
        string word;
        vector<string> alpha;
        while(st>>word)
        {
            alpha.push_back(word);
        }
        // now we have every word stored as a single word in alpha vector
        // but without whitespaces
        // eg: Input: s = "Let's take LeetCode contest"
        // alpha: ["Let's", "take", "LeetCode", "contest"]
        
        // now i loop over alpha and reverse every single word
        // and then combine them
        string res="";
        for(int i=0; i<alpha.size(); i++)
        {
            reverse(alpha[i].begin(), alpha[i].end()); // or use 2 pointers instead of in built
            res+=alpha[i];
            res+=" ";
        }
        // after above for loop
        // res: "s'teL ekat edoCteeL tsetnoc " wth white space at end
        // we remove that one white space by pop back
        res.pop_back();
        return res;
    }
};
