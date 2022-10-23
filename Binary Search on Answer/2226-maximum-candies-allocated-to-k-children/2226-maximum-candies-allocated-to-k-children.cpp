class Solution {
public:
    bool possibleCandies(long long mid, vector<int>& candies, long long k)
    {
        // we check the the ans by dividing all ele of candies
        // by mid and then add the ele of new vector
        // and check if its >=k
        // eg: we consider example 1 of question
        // [5,8,6] if ans is 5 we divide all ele by 5 [5/5,8/5,6/5]
        // comes out to be [1,1,1] now all the ele sum is equal to 3 which is ==k for that question
        long long kids=0;
        for(int i=0; i<candies.size(); i++)
        {
            kids+=(candies[i]/mid);
        }
        if(kids>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // we can peform a bs on the answer
        // for that we have to identify the search space where our answer would lie
        // the min range of search space will be 1
        // the max value of search space will be max(candies)
        // since lets say we have one kid then the max pile goes to him which is max candies
        // so now we do bs on [1,max(candies)]
        long long left=1;
        long long right=*max_element(candies.begin(), candies.end());
        long long ans=0;
        while(left<=right)
        {
            long long mid=left+(right-left)/2; // integer overflow
            if(possibleCandies(mid, candies, k))
            {
                // if its possible to divide we max ans equal to mid
                ans=mid;
                // we keep on looking for maximum now
                left=mid+1;
            }
            // if not possible then we look for ans in right direction
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};