class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        int num=0;
        vector<int>count;
        string ans="";
        int n= s.size();
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i])){
                num=num*10+s[i]-'0';
            }
            else if(s[i]=='['){
                count.push_back(num);
                st.push(ans);
                num=0;
                ans="";
            }
            else if(s[i]==']'){
                int reps= count.back();
                count.pop_back();
                string last_str=st.top();
                st.pop();
                
                while(reps--){
                    last_str+=ans;
                }
                ans=last_str;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};