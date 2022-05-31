class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // k size ki saari unique substrings store karo set ka use karke
        // ab total no of k size strings will be 2^k toh check if set ka size is that or not
        if(s.length()<k) return false;
        unordered_set<string> st;
        for(int i=0; i<s.length()-k+1; i++)
        {
            st.insert(s.substr(i, k));
        }
        return st.size()==pow(2, k);
    }
};