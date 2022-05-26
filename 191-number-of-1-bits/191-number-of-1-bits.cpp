class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int i = 32;
        // int count = 0;
        // while (i>0)
        // {
        //     if ((n&1) == 1)
        //     {
        //         count++;
        //     }
        //     n = n>>1;
        //     i--;
        // }
        // return count;
        bitset<32>st(n);
        return st.count();
    }
};