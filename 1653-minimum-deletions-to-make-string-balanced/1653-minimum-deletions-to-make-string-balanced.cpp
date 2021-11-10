class Solution {
public:
    int minimumDeletions(string s) {
        int res=0;
        int count_a=0;
        for(int i=s.length(); i>=0; i--)
        {
            if(s[i]=='b' && count_a>0)
            {
                res++;
                count_a--;
            }
            else
            {
                if(s[i]=='a')
                {
                    count_a++;
                }
            }
        }
        return res;
    }
};