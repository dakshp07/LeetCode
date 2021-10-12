class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int length=s.length();
        string ans;
        for(int i=0; i<length; i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.top()==s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};