class Solution {
public:
    int hammingDistance(int x, int y) {
        int xors = x^y;
        int ans=0;
        for(int i=0; i<32; i++)
        {
            if(((xors>>i)&1)==1)
            {
                ans++;
            }
        }
        return ans;
    }
};