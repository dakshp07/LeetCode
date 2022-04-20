class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // freq store karo
        vector<int> freq(501, 0);
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        // agar kissi element ki freq odd huyi toh nhi bana paayenge pairs
        bool ok=true;
        for(int i=0; i<501; i++)
        {
            if(freq[i]%2!=0)
            {
                ok=false;
                break;
            }
        }
        return ok;
    }
};