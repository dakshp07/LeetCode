class Solution {
public:
    // agar palindrome already hain toh 1 step
    // warna 2 step
    // bbabb -> 1
    // babbb -> a nikal do (1) -> bbbb -> 1 step kyuki palindrome -> total: 2
    bool isPal(string s)
    {
        int i=0, j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    int removePalindromeSub(string s) {
        // khali ka 0
        if(s.length()==0) return 0;
        if(isPal(s))
        {
            return 1;
        }
        return 2;
    }
};