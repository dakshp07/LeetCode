class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int i = 0;
        for(i=0;i<s.length();i++){
            if(s[i] == '(' ){
                st.push(i);
            }   
            else if(s[i]==')' && !st.empty()){
                st.pop();
            }
            else if(s[i] == ')' && st.empty()){
                s[i]='@';
            }
        }
        while(!st.empty()){
            s[st.top()] = '@';
            st.pop();
        }
        string res;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='@')
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};