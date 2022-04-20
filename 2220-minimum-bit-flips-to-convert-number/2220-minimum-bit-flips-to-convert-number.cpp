class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<64> s(start), g(goal);
        string ss=s.to_string();
        string gg=g.to_string();
        int cnt=0;
        for(int i=0; i<ss.length(); i++)
        {
            if(ss[i]!=gg[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};