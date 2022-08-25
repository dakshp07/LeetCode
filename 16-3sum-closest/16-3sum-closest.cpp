class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // for loop for one ele and then binary search for the other 2 ele
        int length=nums.size();
        // intialize sum as nums[0]+nums[1]+nums[length-1];
        int res=nums[0]+nums[1]+nums[length-1];
        sort(nums.begin(), nums.end()); // sort the array
        for(int i=0; i<length-2; i++) // i starts from 0
        {
            int a=i+1; // a from 1
            int b=length-1; // and b from n-1
            while(a<b) // binary search
            {
                // calculate the sum here instead of mid
                int sum=nums[a]+nums[b]+nums[i];
                // we check if sum > target
                if(sum>target)
                {
                    // we decrement b and move left from right
                    b--;
                }
                else
                {
                    // else we go on right side by increasing a
                    a++;
                }
                // if this sum's abs diff is less then we update our res
                if(abs(sum-target)<abs(res-target))
                {
                    // update res
                    res=sum;
                }
            }
        }
        // return res
        return res;
    }
};