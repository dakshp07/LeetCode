class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        if(n>m) 
        {
            return false;
        }
        int i=0, j=0;
        while(j<m)
            {
                if(i<n && name[i]==typed[j])
                {
                    i++;
                }
                else if(j==0 || typed[j]!=typed[j-1]) 
                {
                    return false;
                }
            j++;
        }
        return i==n;
    }
};