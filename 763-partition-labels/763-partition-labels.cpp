class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_occ(26);
        vector<int> res;
        for(int i=0; i<s.length(); i++)
        {
            last_occ[s[i]-'a']=i;
        }
        int start=0, end=0;
        for(int i=0; i<s.length(); i++)
        {
            end=max(end, last_occ[s[i]-'a']);
            if(i==end)
            {
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
    }
};