class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // we dont have to do anything to chars
        // we just need to get rid of wrong paras
        // so we keep track of index
        // if we want to exclude any index we keep # at its pos in string
        // we push all index of open para and pop them one by one as we see a close para
        stack<int> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(') st.push(i); // push all open para
            else if(s[i]==')' && !st.empty())
            {
                // we need to pop the ele from stack as it will open bracket
                st.pop();
            }
            // now if we see an close para and my stack is empty then i know
            // we need to ignore this in our ans
            else if(s[i]==')' && st.empty())
            {
                // mark this index in string
                s[i]='#';
            }
        }
        // now there still might be some para which are not paired
        // so we mark them too
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
        }
        // now we iterate over s and ignore all # indexes
        string res;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!='#') res+=s[i];
        }
        return res;
    }
};