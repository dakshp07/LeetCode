class Solution {
public:
    int findComplement(int n) {
        if(n==0){
            return 1;
        }
        int len=0,num=n;
        while(num!=0){
            len++;
            num/=2;
        }
        long long int m=pow(2,len)-1;
        return m-n;
    }
};