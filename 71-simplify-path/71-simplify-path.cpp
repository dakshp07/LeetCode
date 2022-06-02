class Solution {
public:
    string simplifyPath(string path) {
        // stack ka standard question
        stack<string> st;
        for(int i=0; i<path.length(); i++)
        {
            // end main laga denge /
            if(path[i]=='/') continue;
            // char ko temp main daalo jab taak / nhi aata
            string temp="";
            while(i<path.length() && path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            // agar 1 . aaya toh continue
            if(temp==".") continue;
            // agar 2 .. aagaye toh pop
            if(temp=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            // baaki sab condition main push
            else st.push(temp);
        }
        // ab stack khali karo
        string res="";
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        // agar kuch nhi baacha
        if(res.length()==0) return "/";
        return res;
    }
};