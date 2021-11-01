class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> res;
        int length=nums.size();
        for(int i=0; i<length; i++)
        {
            umap[nums[i]]++;
        }
        for(auto x: umap)
        {
            if(x.second>length/3)
            {
                res.push_back(x.first);
            }
        }
        return res;
    }
};