class Solution {
public:
    bool isDivide(int x)
    {
        int temp=x;
        while(x!=0)
        {
            int rem=x%10;
            if(rem==0 || temp%rem!=0)
            {
                return false;
            }
            x/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++)
        {
            if(isDivide(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};