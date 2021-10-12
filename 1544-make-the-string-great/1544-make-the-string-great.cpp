class Solution {
public:
    string makeGood(string s) {
        stack<int> st;
        string ans;
        int length=s.length();
        for(int i=length-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(abs(s[i]-st.top())==32)
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while(st.empty()==false)
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};