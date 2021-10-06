class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101);
        int length=nums.size();
        for(int i=0; i<length; i++)
        {
            count[nums[i]]++;
        }
        for(int i=1; i<count.size(); i++)
        {
            count[i]+=count[i-1];
        }
        for(int i=0; i<length; i++)
        {
            int position=nums[i];
            if(position==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=count[position-1];
            }
        }
        return nums;
    }
};