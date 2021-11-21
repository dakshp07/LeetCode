class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res=INT_MIN;
        int len=colors.size();
        for(int i=0; i<len; i++)
        {
            if(colors[i]!=colors[0])
            {
                res=max(res, i);
            }
            if(colors[i]!=colors[len-1])
            {
                res=max(res, len-1-i);
            }
        }
        return res;
    }
};