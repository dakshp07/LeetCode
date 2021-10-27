class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26);
        for(int i=0; i<s.length(); i++)
        {
            last_index[s[i]-'a']=i;
        }
        vector<int> res;
        int left=0;
        int right=0;
        for(int i=0; i<s.length(); i++)
        {
            right=max(right, last_index[s[i]-'a']);
            if(i==right)
            {
                res.push_back(right-left+1);
                left=right+1;
            }
        }
        return res;
    }
};