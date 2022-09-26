class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // one way is to use two stacks and run through both strings parallely
        // tc: O(n) and sc: O(2*n) at max where n is size of s,t
        // other way is to use one stack and empty it everytime after processing one string
        // tc: O(2*n) and sc: O(n) at max where n is size of s,t
        stack<char> st;
        // first we process s
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='#' && st.empty()) continue;
            if(s[i]!='#')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        // now lets create resulatant string of s
        string ress="";
        while(!st.empty())
        {
            ress+=st.top();
            st.pop();
        }
        // next we process t
        for(int i=0; i<t.size(); i++)
        {   
            if(t[i]=='#' && st.empty()) continue;
            if(t[i]!='#')
            {
                st.push(t[i]);
            }
            else
            {
                st.pop();
            }
        }
        // now lets create resulatant string of t
        string rest="";
        while(!st.empty())
        {
            rest+=st.top();
            st.pop();
        }
        return ress==rest;
    }
};