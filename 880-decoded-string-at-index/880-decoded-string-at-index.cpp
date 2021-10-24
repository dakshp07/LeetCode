class Solution {
public:
    string decodeAtIndex(string s, int K) {
        long long int size=0,i;
        for(i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
                size=size*(s[i]-'0');
            else
                size++;
        }
        for(i=s.size()-1;i>=0;i--)
        {
            K=K%size;
        
            if((K==0 || K==size ) && isalpha(s[i]))
            {
                string news="";
                news.push_back(s[i]);
                return news;
            }
        if(isdigit(s[i]))
            size=size/(s[i]-'0');
        
        else
            size--;
        }
        return NULL;
    }
};