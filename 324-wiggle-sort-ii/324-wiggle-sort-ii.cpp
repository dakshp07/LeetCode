class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> res(nums.size());
        res=nums;
        sort(res.begin(), res.end());
        int in=nums.size()-1;
        for(int i=1; i<nums.size(); i+=2)
        {
            nums[i]=res[in];
            in--;
        }
        for(int i=0; i<nums.size(); i+=2)
        {
            nums[i]=res[in];
            in--;
        }
    }
};