class Solution {
public:
    int addDigits(int n) {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        if(sum/10==0)return sum;
        return addDigits(sum);
    }
};