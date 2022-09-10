class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // a bitonic sequence can be first increasing and then decreasing
	    // but a bitcoin sequence could be just either increasing or just decreasing
	    // our approach in order to find the increasing, decreasing sequence will be to first identify the lis from left to right
	    // and then indetify the lis from right to left
	    // and then the ans would be the index where the sum of these two dp values is max
	    // we subtract -1 from those value because the ith ele gets considered twice
	    int n=nums.size();
	    vector<int> dp_lr(n);
	    vector<int> dp_rl(n);
	    // we go for left to right first
	    for(int i=0; i<n; i++)
	    {
	        dp_lr[i]=1;
	        for(int prev=0; prev<i; prev++)
	        {
	            if(nums[i]>nums[prev] && 1+dp_lr[prev]>dp_lr[i])
	            {
	                dp_lr[i]=1+dp_lr[prev];
	            }
	        }
	    }
	    // next we go for right to left
	    for(int i=n-1; i>=0; i--)
	    {
	        dp_rl[i]=1;
	        for(int prev=n-1; prev>i; prev--)
	        {
	            if(nums[i]>nums[prev] && 1+dp_rl[prev]>dp_rl[i])
	            {
	                dp_rl[i]=1+dp_rl[prev];
	            }
	        }
	    }
	    // now we store these dp values in bitonic array where ith ele is sum of dp values-1
	    vector<int> bitonic(n);
	    for(int i=0; i<n; i++)
	    {
	        bitonic[i]=dp_lr[i]+dp_rl[i]-1;
	    }
	    // lets get the max value from bitonic array
	    int mx=*max_element(bitonic.begin(), bitonic.end());
	    return mx;
	}
};
