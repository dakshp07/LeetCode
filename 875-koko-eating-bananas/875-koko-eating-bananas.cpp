class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        // for(int i=0; i<piles.size(); i++)
        // {
        //     right=max(piles[i], right);
        // }
        while(left<right)
        {
            int hours=0;
            int mid=(left+right)/2;
            for(int i=0; i<piles.size(); i++)
            {
                hours+=piles[i]/mid+(piles[i] % mid != 0);
            }
            if(hours<=h)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return right;
    }
};