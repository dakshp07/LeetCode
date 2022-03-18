class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> st;
        vector<bool> visited(26);
        vector<int> last_index(26);
        for(int i=0; i<s.length(); i++)
        {
            last_index[s[i]-'a']=i;
        }
        for(int i=0; i<s.length(); i++)
        {
            if(visited[s[i]-'a'])
            {
                continue;
            }
            while(!st.empty() && st.top()>s[i]-'a' && i<last_index[st.top()])
            {
                visited[st.top()]=false;
                st.pop();
            }
            st.push(s[i]-'a');
            visited[s[i]-'a']=true;
        }
        string res;
        while(!st.empty())
        {
            res.push_back(st.top()+'a');
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};