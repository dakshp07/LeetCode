class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        for(auto x:umap)
        {
            if(x.second==1)
            {
                res.push_back(x.first);
            }
        }
        return res;
    }
};