class Solution {
public:
    int myAtoi(string s) {
        // normal way se karenge
        int sign=1;
        int res=0;
        int i=0;
        while(i<s.length() && s[i]==' ')
        {
            i++; // skip white spaces
        }
        if(i<s.length() && s[i]=='-')
        {
            sign=-1; // make sign as -1 if the char is negative
            i++;
        }
        else if(i<s.length() && s[i]=='+')
        {
            sign=1; // make sign as 1 if the char is positive
            i++;
        }
        while(i<s.length() && isdigit(s[i]))
        {
            // if we get a digit
            int dig=s[i]-'0';
            // check overflow and underflow
            if((res>INT_MAX/10) || (res==INT_MAX/10 && dig>INT_MAX%10))
            {
                // now if we had a postiive int we return INT_MAX 
                if(sign==1) return INT_MAX;
                // else if the sign is negative we return INT_MIN
                else return INT_MIN;
            }
            // append the digit to res
            res=res*10+dig;
            i++;
        }
        return sign*res;
    }
};