class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int count=0;
        int sum=0;
        umap[0]=1;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(umap.find(sum-k)!=umap.end())
            {
                count+=umap[sum-k];
            }
            umap[sum]++;
        }
        return count;
    }
};