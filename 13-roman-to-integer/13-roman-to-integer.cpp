class Solution {
public:
    // all the roman in int
    int value(char r)
    {
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++)
        {
            int num1=value(s[i]);
            if(i+1<s.size())
            {
                int num2=value(s[i+1]);
                if(num2>num1)
                {
                    ans=ans+(num2-num1);
                    i++;
                }
                if(num2<=num1)
                {
                    ans=ans+num1;
                }
            }
            else
            {
                ans+=num1;
            }
        }
        return ans;
    }
};