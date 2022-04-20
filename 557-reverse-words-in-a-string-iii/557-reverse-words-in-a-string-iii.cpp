class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream st(s);
        string word;
        while(st>>word)
        {
            words.push_back(word);
        }
        string ans="";
        for(int i=0; i<words.size(); i++)
        {
            string temp=words[i];
            reverse(temp.begin(), temp.end());
            ans+=temp;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};