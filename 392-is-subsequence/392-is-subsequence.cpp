class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())
        {
            return false;
        }
        if(s=="" && t=="")
        {
            return true;
        }
        int j=0;
        bool ok=false;
        for(int i=0; i<t.length(); i++) // since t.len>s.len
        {
            if(t[i]==s[j])
            {
                j++;
            }
            if(j==s.length())
            {
                // since we traverse whole string of s
                // and at no point we didnt went out of the above condition
                ok=true;
                break;
            }
        }
        return ok;
    }
};