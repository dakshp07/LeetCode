class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // we can use a set and add ele in it
        // if we see any ele which is already in set we retun true
        // tc: O(n) and sc: O(n)
        // the other method is to sort and then see if any two consecutive ele are same
        // tc: O(nlogn) and sc: O(1)
        // instead of set we can also use a vis array
        // tc: O(n) and sc: O(n)
        set<int> st;
        for(int i=0; i<nums.size(); i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};