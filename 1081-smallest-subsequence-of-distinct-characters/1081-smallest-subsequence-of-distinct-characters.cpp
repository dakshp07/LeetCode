class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> alpha(26);
        vector<int> vis(26);
        for(int i=0; i<s.length(); i++)
        {
            alpha[s[i]-'a']=i;
        }
        for(int i=0; i<s.length(); i++)
        {
            if(vis[s[i]-'a'])
            {
                continue;
            }
            while(!st.empty() && st.top()>s[i] && i<alpha[st.top()-'a'])
            {
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};