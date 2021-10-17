class Solution {
public:
    bool isSubSeq(string &a,string &b)
    {
        int m=a.size();
        int n=b.size();
        
        int i=0,j=0;
        
        while(i<m && j<n)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return j==n;
    }
    string findLongestWord(string s, vector<string>& dic) {
        sort(dic.begin(),dic.end(),[&](string &a,string &b){
            int m=a.size();
            int n=b.size();
            
            if(m==n)
            {
                for(int i=0;i<m;i++)
                {
                    if(a[i]<=b[i])
                        return true;
                    else
                        return false;
                }
                //return false;
            }
            
            return m>n;
        });
        
        int n=dic.size();
        
        for(int i=0;i<n;i++)
        {
            if(isSubSeq(s,dic[i]))
            {
                return dic[i];
            }
        }
        
        return "";
    }
};