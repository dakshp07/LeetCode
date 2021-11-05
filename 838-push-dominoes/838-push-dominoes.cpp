class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> forces(dominoes.length());
        int force=0;
        for(int i=0; i<dominoes.length(); i++)
        {
            if(dominoes[i]=='R')
            {
                force=dominoes.length();
            }
            else if(dominoes[i]=='L')
            {
                force=0;
            }
            else
            {
                force=max(force-1, 0);
            }
            forces[i]+=force;
        }
        force=0;
        for(int i=dominoes.length()-1; i>=0; i--)
        {
            if(dominoes[i]=='L')
            {
                force=dominoes.length();
            }
            else if(dominoes[i]=='R')
            {
                force=0;
            }
            else
            {
                force=max(force-1, 0);
            }
            forces[i]-=force;
        }
        string res="";
        for(int i=0; i<forces.size(); i++)
        {
            if(forces[i]>0)
            {
                res+="R";
            }
            else if(forces[i]<0)
            {
                res+="L";
            }
            else
            {
                res+=".";
            }
        }
        return res;
    }
};