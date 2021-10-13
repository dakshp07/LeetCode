class Solution {
public:
    static bool comp(int a, int b){
        return (to_string(a)+to_string(b) > to_string(b)+to_string(a));
    }
    
    string largestNumber(vector<int>& nums) {
        int length=nums.size();
        int i=0;
        int j=1;
        sort(nums.begin(), nums.end(), comp);
        string ans;
        for(int i=0; i<length; i++)
        {
            ans+=to_string(nums[i]);
        }
        if(nums[0] == 0) 
        {
            ans="0";
        }
        return ans;
    }
};