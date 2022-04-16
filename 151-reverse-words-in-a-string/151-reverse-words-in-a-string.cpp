class Solution {
public:
    string reverseWords(string s) {
        stringstream chars(s);
        string word;
        vector<string> alphabet;
        while(chars>>word)
        {
            alphabet.push_back(word);
        }
        reverse(alphabet.begin(), alphabet.end());
        string temp="";
        for(int i=0; i<alphabet.size(); i++)
        {
            temp+=alphabet[i];
            temp+=" ";
        }
        temp.pop_back();
        return temp;
    }
};