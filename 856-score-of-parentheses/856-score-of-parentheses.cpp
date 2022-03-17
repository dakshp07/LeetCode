class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int> st;
        int sc=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(sc);
                sc=0;
            }
            else
            {
                sc=st.top()+max(2*sc, 1);
                st.pop();
            }
        }
        return sc;
    }
};