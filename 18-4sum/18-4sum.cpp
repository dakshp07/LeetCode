class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // i, j ko starting main rakho
        // and then keep left after j and right at end
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) // starts from starting
        {
            for(int j=i+1; j<nums.size(); j++) // starts from i+1
            {
                long target_2=target-(long long)nums[j]-(long long)nums[i]; // now we will be use the two pointer approach to find traget_2
                int left=j+1;
                int right=nums.size()-1;
                while(left<right)
                {
                    int two_sum=nums[right]+nums[left];
                    if(two_sum<target_2) left++;
                    else if(two_sum>target_2) right--;
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        res.push_back(quad);
                        // we cant keep duplicates
                        // so we will process them one by one
                        // duplicates of start
                        while(left<right && nums[left]==quad[2]) left++;
                        // duplicates of end
                        while(left<right && nums[right]==quad[3]) right--;
                    }
                }
                // duplicates of j
                while(j+1<nums.size() && nums[j+1]==nums[j]) j++;
            }
            // duplicates of i
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};