class Solution {
public:
    int calculate(string s) {
        s += '+'; // to kick of the first ele of string as we need to anyways add to end
        // we traverse and use a stack
        stack<int> st;
        long long curr=0; // holds current number
        char op='+'; // holds current operations (+,-,/,*)
        for(int i=0; i<s.length(); i++)
        {
            // if the s[i] is digit
            // we push to stack
            if(isdigit(s[i]))
            {
                curr=curr*10+(s[i]-'0');
            }
            // if its not digit
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                // now we do op operations
                if(op=='+') st.push(curr);
                else if(op=='-') st.push(-curr);
                // since +,- are last in order we just push them with signs
                // whereas *,/ are the first ones we get the ans of their calculations and push them
                else if(op=='*') 
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp*curr);
                }
                else if(op=='/') 
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp/curr);
                }
                // now we update the op to current char and also update curr
                curr=0;
                op=s[i];
            }
        }
        long long sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};