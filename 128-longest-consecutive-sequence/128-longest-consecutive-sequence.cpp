class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort kar sakte hain but that will be O(nlogn) time
        // sort karke dekhte hain
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int mxStreak=1, currStreak=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                currStreak++;
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
                mxStreak=max(mxStreak, currStreak);
                currStreak=1;
            }
        }
        return max(mxStreak, currStreak);
    }
};