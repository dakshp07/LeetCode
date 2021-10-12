class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int low=1;
        vector<string> res;
        for(int i=0; i<target.size(); i++)
        {
            while(low<target[i])
            {
                res.push_back("Push");
                res.push_back("Pop");
                low++;
            }
            res.push_back("Push");
            low++;
        }
        return res;
    }
};