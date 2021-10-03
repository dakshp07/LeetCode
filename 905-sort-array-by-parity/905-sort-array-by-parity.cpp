class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res(nums.size());
        int length=nums.size();
        int counter=0;
        for(int i=0; i<length; i++)
        {
            if(nums[i]%2==0)
            {
                res[counter]=nums[i];
                counter+=1;
            }
        }
        for(int i=0; i<length; i++)
        {
            if(nums[i]%2==1)
            {
                res[counter]=nums[i];
                counter+=1;
            }
        }
        return res;
    }
};