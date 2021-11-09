class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str2 = s;
        for(int i = 0; i < indices.size(); i++){
            str2[indices[i]] = s[i];
        }
        return str2;
    }
};