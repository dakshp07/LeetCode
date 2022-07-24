class Solution {
public:
    int candy(vector<int>& ratings) {
        // rules:
        /*
        1.Each child must have at least one candy.
        2. Children with a higher rating get more candies than their neighbors.
        */
        // one way: lets make 2 arrays, and fill them with 1s since all should have atleast one candy
        // now traverse from left to right and check if any one has > rating than its prev one, in this case we offer him +1 candy. store ans in some array (vec1)
        // now traverse from right to left and check if any one has > rating than its prev one, in this case we offer him +1 candy. store ans in some array (vec2)
        // since we need to keep track of both neighbors we take max of vec1 and vec2 as ans
        
        // int n=ratings.size();
        // vector<int> lr(n, 1);
        // vector<int> rl(n, 1);
        // for(int i=1; i<n; i++)
        // {
        //     if(ratings[i]>ratings[i-1])
        //     {
        //         lr[i]=lr[i-1]+1;
        //     }
        // }
        // for(int i=n-2; i>=0; i--)
        // {
        //     if(ratings[i]>ratings[i+1])
        //     {
        //         rl[i]=rl[i+1]+1;
        //     }
        // }
        // int ans=0;
        // for(int i=0; i<n; i++)
        // {
        // ans+=max(lr[i], rl[i]);
        // }
        // return ans;
        
        // optimise way: remove one of the two arrays. reduces sc by one n
        // much better: sc: O(1)
        // we check the slope and the plataeu
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n)
        {
            if(ratings[i] == ratings[i-1])
            {
                i++;
                continue;
            }
            // For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1])
            {
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            // For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1])
            {
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); // Keep only the higher peak
        }
        return candy;
    }
};