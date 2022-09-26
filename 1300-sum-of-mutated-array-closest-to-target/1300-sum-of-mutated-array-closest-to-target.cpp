class Solution {
public:
    int get_sum(vector<int>& arr, int x)
    {
        int sum=0;
        for(int i=0; i<arr.size(); i++)
        {
            // we add x to sum if arr[i]>=x
            if(arr[i]>=x)
            {
                sum+=x;
            }
            // else we just add arr[i] to sum
            else
            {
                sum+=arr[i];
            }
            
        }
        return sum; // return sum
    }
    int findBestValue(vector<int>& arr, int target) {
        // we can run a binary search from [0,max_ele_in_array]
        int left=0;
        int right=*max_element(arr.begin(), arr.end());
        int ans=INT_MAX;
        // min diff to keep track of min diff
        int min_diff=INT_MAX;
        while(left<=right)
        {
            int mid=(left+right)/2;
            // now we replace all ele in arr with value >val and get their sum
            int sum=get_sum(arr, mid);
            // current diff
            int diff=abs(sum-target);
            // now we change boundaries
            if(sum>target)
            {
                right=mid-1;
            }
            else if(sum<target)
            {
                left=mid+1;
            }
            else
            {
                return mid;
            }
            // if we get a diff which is less than current diff we update the min diff and the ans
            if(min_diff>diff)
            {
                ans=mid;
                min_diff=diff;
            }
            // if we get another diff which is equal to current diff then we take min of ans,mid
            else if(min_diff==diff)
            {
                ans=min(ans, mid);
            }
        }
        return ans;
    }
};