class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        int n = path.size();
        while(i < n)
        {
            string temp;
            while(path[i] == '/' && i < n) i++;
            while(path[i] != '/'&& i < n) temp += path[i++];
            if(temp == ".." && !st.empty())st.pop();
            else if(temp == "." || temp == "")continue;
            else if(temp != "..") st.push(temp);
        }
        string res = "";
        while(!st.empty())
        {
            res = '/' + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/":res;
    }
};