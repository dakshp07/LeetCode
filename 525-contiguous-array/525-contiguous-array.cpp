class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count=0, max_len=0;
        unordered_map<int, int> mp;
        mp[count]=-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count--;
            }
            else
            {
                count++;
            }
            if(mp.find(count)!=mp.end())
            {
                max_len=max(max_len, i-mp[count]);
            }
            else
            {
                mp[count]=i;
            }
        }
        return max_len;
    }
};