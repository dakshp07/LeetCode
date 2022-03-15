class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> st;
        map<string, int> mp;
        for(int i=0; i<paths.size(); i++)
        {
            mp[paths[i][0]]++;
            st.insert(paths[i][0]);
            st.insert(paths[i][1]);
        }
        for(auto &x: mp)
        {
            st.erase(x.first);
        }
        string res;
        for(auto &x: st)
        {
            res=x;
        }
        return res;
    }
};