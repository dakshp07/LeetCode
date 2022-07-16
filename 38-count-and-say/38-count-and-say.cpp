class Solution {
public:
    string countAndSay(int n) {
        // just iterate over the string and keep a counter
        // the counter will help us keep track if i th nd (i-1)th are same or not
        // if in case they are diff we add the ele count times in our ans string
        // base case when n is 1 or 2
        if(n==1) return "1";
        if(n==2) return "11";
        // starting with 2
        string s="11";
        // iterate from 3
        for(int i=3; i<=n; i++)
        {
            // will store our strings here
            string t="";
            int count=1; // count variable
            s+='&';
            for(int j=1; j<s.size(); j++)
            {
                // applying the rule to see if j and j-1 are same or not
                if(s[j]!=s[j-1])
                {
                    // make the count to add in t
                    t=t+to_string(count);
                    t=t+s[j-1]; // add that char at s
                    count=1; // make count as 1 again
                }
                else
                {
                    count++;
                }
            }
            s=t;
        }
        return s;
    }
};