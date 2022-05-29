class Solution {
public:
    int getBits(string str)
    {
        int s=0;
        for(int i=0; i<str.length(); i++)
        {
            int in=str[i]-'a';
            s|=1<<(in);
        }
        return s;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> state(n);
        for(int i=0; i<n; i++)
        {
                state[i]=getBits(words[i]);
        }
        int mx=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if((state[i]&state[j])==0)
                {
                    if(words[i].length()*words[j].length()>mx)
                    {
                        mx=words[i].length()*words[j].length();
                    }
                }
            }
        }
        return mx;
    }
};