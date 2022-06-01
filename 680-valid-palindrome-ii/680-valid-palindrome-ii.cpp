class Solution {
public:
    bool isPalindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // phele toh normal check karo agar koi 2 char same nhi toh unko nikal ke dekho
        int i=0, j=s.length()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};
