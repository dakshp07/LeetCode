class Solution {
public:
    int minAddToMakeValid(string s) {
        // open close var banao
        int open=0, close=0;
        for(int i=0; i<s.length(); i++)
        {
            // open dikha toh open ko increment
            if(s[i]=='(') open++;
            // close dikhe toh 2 condition
            else if(s[i]==')')
            {
                // agar open dikhe the ie open>0 toh open ki value -1 kyuki balance hoga
                if(open>0)
                {
                    open--;
                }
                // warna close ko +1 kardo
                else
                {
                    close++;
                }
            }
        }
        // end main total no of brackets req will be open+close
        return open+close;
    }
};