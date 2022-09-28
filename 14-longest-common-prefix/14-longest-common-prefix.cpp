class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // we consider the first string from array as the prefix
        // and then slow strike off to get our prefix
        string prefix=strs[0];
        for(int i=0; i<strs.size(); i++)
        {
            // will iterate over current string and our prefix
            int j=0;
            string curr=strs[i];
            while(j<curr.size())
            {
                if(curr[j]==prefix[j]) j++;
                else break;
            }
            // we break while loop when we reach a point where the chars are diff
            // then we break the prefix string from here
            prefix=prefix.substr(0, j);
        }
        return prefix;
    }
};