class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // brute force kaam karega kyuki 1000 hain
        // use 3 loops and return the answers O(n^3)
        // how to optimise?
        // we can use two loops and then do a binary search for third sise
        // a, b, c && condi: a+b<c so i will pick a, b and look for c
        // tc: O(n^2 log n)
        int cnt=0;
        if(nums.size()<3) return cnt;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++)
        {
            for(int j=i+1; j<nums.size()-1; j++)
            {
                // now binary search for third one
                int a=nums[i];
                int b=nums[j];
                int low=j+1;
                int high=nums.size()-1;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    int c=nums[mid];
                    if(a+b<=c)
                    {
                        // i will look for more smaller c
                        high=mid-1;
                    }
                    else
                    {
                        low=mid+1;
                    }
                }
                // low has the index where we got out ans
                cnt+=(high-j); // the cnt of triplet
            }
        }
        return cnt;
    }
};