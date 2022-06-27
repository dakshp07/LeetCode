class Solution {
public:
    int minPartitions(string n) {
        // we can observe the minimum number of deci-binaries required to create the required n is the max digit in the input n.
        return *max_element(n.begin(), n.end())-'0';
    }
};