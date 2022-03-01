class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++)
        {
            bitset<32> bt(i);
            res.push_back(bt.count());
        }
        return res;
    }
};