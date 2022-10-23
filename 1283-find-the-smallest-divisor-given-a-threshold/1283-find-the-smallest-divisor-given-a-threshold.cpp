class Solution {
public:
    bool possibleAns(int mid, vector<int>& nums, int threshold)
    {
        int sums=0;
        for(int i=0; i<nums.size(); i++)
        {
            // since the example 1 says we take > or =. eg: 7/3 = 3. so we take ceil
            sums+=ceil((double)nums[i]/mid);
        }
        // if sums<=threshold (given in question) we retun true
        if(sums<=threshold) return true;
        // else return false
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // so here we can have many possible answers
        // which means we can peform a bs on ans space
        // our range of ss will go from 1 to max(nums)
        // because the best case would be when threshold is sum(nums) then i divide all by 1
        // the next case would be when my threshold is 1 so i divide all by max(nums)
        // hence our ans lies b/w [1,max(nums)]
        // a checker function will make sure that we pick minimum possible ans
        int left=1;
        int right=*max_element(nums.begin(), nums.end());
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(possibleAns(mid, nums, threshold))
            {
                ans=mid;
                // we keep on looking on left for more small ans
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};