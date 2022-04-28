class Solution {
public:
    vector<int> sumZero(int n) {
        int num=n/2;
        int ptr=0-num;
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(n%2==0 && ptr==0)
            {
                ptr++;
                continue;
            }
            else
            {
                res.push_back(ptr);
                ptr++;
            }
        }
        if(n%2==0) res.push_back(num);
        return res;
    }
};