class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        for(int i=0; i<words.size(); i++)
        {
            int count=0;
            for(int j=0; j<words[i].length(); j++)
            {
                if(find(allowed.begin(), allowed.end(), words[i][j])!=allowed.end())
                {
                    count++;
                }
            }
            if(count==words[i].length())
            {
                ans++;
            }
        }
        return ans;
    }
};