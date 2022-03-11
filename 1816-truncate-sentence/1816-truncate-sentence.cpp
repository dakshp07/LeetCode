class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
            {
                cnt++;
                res.push_back(' ');
            }
            else
            {
                res.push_back(s[i]);
            }
            if(cnt==k)
            {
                break;
            }
        }
        if(res.back()==' ') res.pop_back();
        return res;
    }
};