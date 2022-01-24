class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ok=false;
        string tempu=word;
        string templ=word;
        transform(templ.begin(), templ.end(), templ.begin(), ::tolower);
        if(templ==word) 
            ok=true;
        transform(tempu.begin(), tempu.end(), tempu.begin(), ::toupper);
        if(tempu==word) 
            ok=true;
        else
        {
            if(isupper(word[0])) ok=true;
            string rest=word.substr(1, word.length()-1);
            transform(rest.begin(), rest.end(), rest.begin(), ::tolower);
            if(rest!=word.substr(1, word.length()-1)) ok=false;
        }
        return ok;
    }
};