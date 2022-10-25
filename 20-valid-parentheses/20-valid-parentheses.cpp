class Solution {
public:
    bool isValid(string s) {
        // we just add opening paranthases in stack
        // and once we see a closing one, we check if its corresponding opener is in stack or not
        if(s.length()%2!=0) return false;
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                else
                {
                    char top=st.top();
                    st.pop();
                    if((top=='(' && s[i]==')') || (top=='[' && s[i]==']') || (top=='{' && s[i]=='}'))
                    {
                        continue;
                    }
                    else return false;
                }
            }
        }
        return st.empty();
    }
};