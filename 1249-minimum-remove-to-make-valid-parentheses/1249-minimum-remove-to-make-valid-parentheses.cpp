class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++)
        {
            // agar open para hain toh push
            if(s[i]=='(')
            {
                st.push(i);
            }
            // agar closed hain or stack empty nhi toh stack ke top pe open hoga uska pop kardo
            else if(s[i]==')' && !st.empty())
            {
                st.pop();
            }
            // agar stack khali hain matlab ye para ka koi pair nhi so exclude
            else if(s[i]==')' && st.empty())
            {
                s[i]='#';
            }
        }
        // abhi agar stack khai nhi huyi matlab kuch para abhi bhi aise hain jinka pair nhi
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
        }
        string res;
        // string banao
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='#')
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};