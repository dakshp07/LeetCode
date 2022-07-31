class Solution {
public:
    string removeDuplicateLetters(string s) {
        // we will keep an array to store the frequency
        // a visited array to keep a check if the the ith char is in resultant string or not
        vector<int> freq(26, 0);
        string res="";
        vector<int> vis(26, 0);
        // store the freq of all char
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++)
        {
            int c=s[i]-'a';
            // decrease the freq of this char as we pick this
            freq[c]--;
            // we check if the char is visited or not
            if(!vis[c])
            {
                // then we will see if the last char of res was > then this char
                // if it was, then we pop back from res until we get a char < then this char
                // and also mark that char as unvisited
                while(res.size()>0 && res.back()>s[i] && freq[res.back()-'a']>0)
                {
                    vis[res.back()-'a']=0;
                    res.pop_back();
                }
                // if res.back()<s[i], then we add it to res and also mark as visited
                res+=s[i];
                vis[c]=1;
            }
        }
        return res;
    }
};