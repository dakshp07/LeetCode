class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            // we keep pushing the ele into the stack until we see a opening bracket
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            // when we see a closing bracket
            else
            {
                // we build a temp string by popping stuff from stack till we see a [
                string temp="";
                while(!st.empty() && st.top()!='[')
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                // pop the opening bracket too
                st.pop();
                // now we keep poping till we see our number
                string num="";
                while(!st.empty() && isdigit(st.top()))
                {
                    num=st.top()+num;
                    st.pop();
                }
                // now we build the temp string by pushing it into the stack nums times
                int nums=stoi(num);
                while(nums!=0)
                {
                    for(int i=0; i<temp.size(); i++)
                    {
                        st.push(temp[i]);
                    }
                    nums--;
                }
            }
        }
        // now we pop the stack and create our res string
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        // we reverse the res
        reverse(res.begin(), res.end());
        return res;
    }
};