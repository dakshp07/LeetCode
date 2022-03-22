class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> res(n, 'a');
        k-=n;
        while(k>0)
        {
            res[--n]+=min(25, k);
            k-=min(25, k);
        }
        string ress="";
        for(int i=0; i<res.size(); i++)
        {
            ress+=res[i];
        }
        return ress;
    }
};