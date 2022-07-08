class Solution {
public:
    int myAtoi(string s) {
        int ind=0;
        int sign=1;
        int n=s.size();
        int res=0;
        // implment rule of whitespaces
        while(ind<n && s[ind]==' ')
        {
            ind++; // skip those indexes
        }
        // lets check sign
        if(ind<n && s[ind]=='+')
        {
            sign=1;
            ind++;
        }
        else if(ind<n && s[ind]=='-')
        {
            sign=-1;
            ind++;
        }
        // next rule is to check all digits
        while(ind<n && isdigit(s[ind]))
        {
            int digit=s[ind]-'0';
            // check overflow and underflow
            if((res>INT_MAX/10) || (res==INT_MAX/10 && digit>INT_MAX%10))
            {
                // now if we had a postiive int we return INT_MAX 
                if(sign==1) return INT_MAX;
                // else if the sign is negative we return INT_MIN
                else return INT_MIN;
            }
            // append the digit to res
            res=res*10+digit;
            ind++;
        }
        // return ans with its sign
        return sign*res;
    }
};