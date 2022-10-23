class Solution {
public:
    bool possibleDivide(int mid, vector<int>& quantities, int n)
    {
        // so now we divide all ele in quantities with mid and take ceil
        // if the sum of all this comes to be >=n we return true or else false
        // lets see first test case
        // [11,6], since ans is 3 we divide all ele by 3
        // [ceil(11/3),ceil(6/3)] == [4,2] whose sum is 6, hence we return true
        int curr_n=0;
        for(int i=0; i<quantities.size(); i++)
        {
            curr_n+=ceil(double(quantities[i])/mid);
        }
        // we return true if our curr_n is <=n as we need to minise the number of product
        if(curr_n<=n) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // we will apply bs on the answer range
        // but for that we need to find the search space
        // the minimum products that we can give is 1 
        // the max we can give is max(quantities) as the best case is when n=1
        int left=1;
        int right=*max_element(quantities.begin(), quantities.end());
        int ans=right; // since i need to return min and the max i can allow is max(quantities)
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(possibleDivide(mid, quantities,n))
            {
                // we update ans
                ans=mid;
                // and look for more smaller ans on left
                right=mid-1;
            }
            else
            {
                // we look for ans on right
                left=mid+1;
            }
        }
        return ans;
    }
};