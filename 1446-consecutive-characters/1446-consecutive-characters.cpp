class Solution {
public:
    int maxPower(string s) {
        int point_1=0, point_2=1, len=1;
        while(point_2<s.length())
        {
            if(s[point_1]!=s[point_2])
            {
                len=max(len, point_2-point_1);
                point_1=point_2;
            }
            point_2++;
        }
        return max(point_2-point_1, len);
    }
};