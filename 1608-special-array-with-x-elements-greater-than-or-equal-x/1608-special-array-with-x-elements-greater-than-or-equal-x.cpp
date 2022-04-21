class Solution {
public:
    int specialArray(vector<int>& nums) {
        // store freq
        vector<int> freq(10001, 0);
        int sum=nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        // now for every freq[i] have the sum of no greater that i
        // return sum or else return -1
        for(int i=0; i<1001; i++)
        {
            if(i==sum)
            {
                return sum;
            }
            else
            {
                sum-=freq[i];
            }
        }
        return -1;
    }
};