vector<int> minChar(string pat)
{
    int M = pat.size();
    vector< int>lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0)
            {
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int Solution::solve(string A) {
    string str = A;
    reverse(str.begin() , str.end());
    string canca = A + "$" + str;
    vector<int>lps = minChar(canca);
   
    return A.size() - lps.back();
}
