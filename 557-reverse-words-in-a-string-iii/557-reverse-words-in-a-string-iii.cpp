class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        // stringstream se words without space store karo
        stringstream st(s);
        string word;
        while(st>>word)
        {
            // vector main store karo words
            words.push_back(word);
        }
        string ans="";
        for(int i=0; i<words.size(); i++)
        {
            // individual words ko reverse karo
            string temp=words[i];
            reverse(temp.begin(), temp.end());
            // ans string main append karo
            ans+=temp;
            // space lagate jaao
            ans+=" ";
        }
        // last space pop back
        ans.pop_back();
        return ans;
    }
};
