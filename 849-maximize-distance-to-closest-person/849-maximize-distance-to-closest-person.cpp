class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prez=-1, maxz=-1, sufz=-1, z=0;
        for(int i=0; i<seats.size(); i++)
        {
            if(seats[i]==0)
            {
                z++;
            }
            else
            {
                if(prez==-1)
                {
                    prez=z;
                }
                else
                {
                    maxz=max(maxz, z);
                }
                z=0;
            }
        }
        sufz=z;
        return max({prez, sufz, (maxz+1)/2});
    }
};