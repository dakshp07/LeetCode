class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        // 1. convert to string and check
        // string org_num=to_string(x);
        // string rev_num=org_num;
        // reverse(rev_num.begin(), rev_num.end());
        // return org_num==rev_num;

        // 2. pick single digit and check
        long rev_num=0;
        long org_num=x;
        while(x>0)
        {
            int last_digit=x%10;
            rev_num=rev_num*10+last_digit;
            x=x/10;
        }
        return org_num==rev_num;
    }
};
