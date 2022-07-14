class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // lets consider the first string in the array as the prefix
        // and then chop off letters as we move ahead
        string prefix=strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            // lets see if we have common in our string
            int j=0;
            while(j<strs[i].length())
            {
                // if we have same stuff we continue
                if(strs[i][j]==prefix[j]) 
                {
                    j++;
                }
                else break;
            }
            // we keep that substring
            prefix=prefix.substr(0, j);
        }
        return prefix;
    }
};