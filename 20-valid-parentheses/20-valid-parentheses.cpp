class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0)
        {
            return false;
        }
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}'))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};