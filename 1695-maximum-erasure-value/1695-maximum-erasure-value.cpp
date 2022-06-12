class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // sliding window lagate hain
        // set ka use karenge 
        // usmain element ko daal denge and as we move if set ha that element then
        // we will slide the window as we need unique ele only
        unordered_set<int> seen;
        int curr_sum=0, mx_sum=0, left=0;
        for(int i=0; i<nums.size(); i++)
        {
            // check if nums[i] was already seen
            while(seen.find(nums[i])!=seen.end())
            {
                // if already seen reduce it from curr_sum
                curr_sum-=nums[left];
                // erase it from seen
                seen.erase(nums[left]);
                // and increment our left to move on
                left+=1;
            }
            // if not seen add its value in curr_sum
            curr_sum+=nums[i];
            // insert it into seen
            seen.insert(nums[i]);
            // update mx_sum
            mx_sum=max(mx_sum, curr_sum);
        }
        return mx_sum;
    }
};