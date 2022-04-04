class Solution {
public:
    bool isPal(string s, int i, int j)
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
        int left=0, right=s.length()-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return isPal(s, left+1, right) || isPal(s, left, right-1);
            }
        }
        return true;
    }
};