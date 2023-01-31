class Solution {
public:
    bool checkRecord(string s) {
        int cnt_a=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='A') cnt_a++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(i>=2)
            {
                if(s[i]=='L' && s[i-1]=='L' && s[i-2]=='L')
                {
                    return false;
                }
            }
        }
        return cnt_a<2;
    }
};
